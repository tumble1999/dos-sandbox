#include "assets.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

void fskip(unsigned bytes, FILE *file) {
	unsigned i;
	for (i = 0; i < bytes; i++)
		fgetc(file);
}

void reverse_bytes(byte *data, unsigned length) {
	byte tmp[length];
	int i, j;
	for (i = 0; i < length; i++) {
		j = length - 1 - i;
		if (j > i) {
			tmp[j] = data[j];
			data[j] = data[i];
		} else {
			data[i] = tmp[i];
		}
	}
}

void load_bitmap(char *path, BITMAP *bitmap) {
	FILE *file = fopen(path, "rb");
	dword i;
	word num_colors;
	int x;

	if (file == NULL) {
		printf("Error Reading file: %s", path);
		exit(1);
	}
	// Type
	if (!(fgetc(file) == 'B' || fgetc(file) == 'M')) {
		printf("Inalid Bitmap file: %s\n", path);
		fclose(file);
		exit(1);
	} else
		printf("Valid Bitmap File: %s\n", path);
	// Skip 16 bytes
	fskip(SIZE_DWORD, file); // Size
	fskip(SIZE_DWORD, file); // Reserved
	fskip(SIZE_DWORD, file); // Offset
	fskip(SIZE_DWORD, file); // headerSize
	// Width
	fread(&bitmap->width, SIZE_DWORD, 1, file);
	reverse_bytes((char *)bitmap->width, SIZE_DWORD);
	fskip(SIZE_DWORD, file);
	// Height
	fread(&bitmap->height, SIZE_DWORD, 1, file);
	reverse_bytes((char *)bitmap->height, SIZE_DWORD);
	fskip(SIZE_DWORD, file);
	fskip(SIZE_WORD, file);	 // Planes
	fskip(SIZE_WORD, file);	 // BitsPerPixel
	fskip(SIZE_DWORD, file); // Compression
	fskip(SIZE_DWORD, file); // SizeImage
	fskip(SIZE_DWORD, file); // XPixelsPerMeter
	fskip(SIZE_DWORD, file); // YPixelsPerMeter
	fskip(SIZE_DWORD, file); // ColorsUsed
	fskip(SIZE_DWORD, file); // ColorsImportant

	// Data
	// fread(&bitmap->data, SIZE_BYTE, bitmap->width * bitmap->height, file);

	printf("Path: %s\nWidth: %d\nHeight: %d\n", path, bitmap->width,
		   bitmap->height);
}