#include "vga.h"

#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <sys/nearptr.h>

#define INT_VIDEO 0x10
#define INT_VIDEO_SETMODE 0x00
#define INT_VIDEO_PLOTPIXEL 0X0C

#define COLOR_COUNT 256;

byte *VGA = (char *)0xa0000;

void video_setmode(byte mode) {
	union REGS regs;
	regs.h.ah = INT_VIDEO_SETMODE;
	regs.h.al = mode;
	int86(INT_VIDEO, &regs, &regs);
}

void vga_init() {
	if (__djgpp_nearptr_enable() == 0) {
		printf("Could get access to first 640K of memory.\n");
		exit(-1);
	}

	VGA += __djgpp_conventional_base;

	video_setmode(VMODE_VGA256);
}

void plot_pixel(int x, int y, byte color) {
	x %= SCREEN_WIDTH;
	y %= SCREEN_HEIGHT;
	color %= COLOR_COUNT;
	VGA[x + y * SCREEN_WIDTH] = color;
}

void draw_bitmap(int x, int y, BITMAP *bitmap) {
	byte data;
	int ix, iy;
	int scale = 1;
	for (iy = 0; iy < bitmap->height * scale; iy++)
		for (ix = 0; ix < bitmap->width * scale; ix++) {

			data = bitmap->data[ix / scale + iy / scale * bitmap->width];
			if (data != 0)
				plot_pixel(ix + x, iy + y, data);
		}
}