#include <stdio.h>
#include <stdlib.h>
#include "vga.h"
#include "assets.h"

int main() {
	BITMAP test_img;
	BITMAP rocket_img;
	test_img.height = test_img.width = 3;
	test_img.data = (char[]){
		COLOR_RED,	 COLOR_RED,	 COLOR_RED,	 COLOR_WHITE, COLOR_LIGHT_GREEN,
		COLOR_WHITE, COLOR_BLUE, COLOR_BLUE, COLOR_BLUE,
	};

	load_bitmap("ASSETS\\ROCKET.BMP", &rocket_img);

	/*vga_init();
	plot_pixel(10, 10, COLOR_LIGHT_RED);
	draw_bitmap(100, 100, &test_img);
	system("pause>nul");

	video_setmode(VMODE_TEXT);*/
	printf("Hello World!\n");
	return 0;
}