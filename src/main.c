#include <stdio.h>
#include <stdlib.h>
#include "vga.h"
#include "assets.h"

int main() {
	BITMAP rocket_img;

	load_bitmap("ASSETS\\ROCKET.BMP", &rocket_img);

	vga_init();

	U x, y;
	for (y = 0; y < SCREEN_HEIGHT; y++) {
		for (x = 0; x < SCREEN_WIDTH; x++) {
			plot_pixel(x, y, (x * y) % 256);
		}
	}

	draw_bitmap(100, 100, &rocket_img);
	system("pause>nul");

	video_setmode(VMODE_TEXT);
	printf("Hello World!\n");
	return 0;
}