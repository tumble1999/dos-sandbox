#ifndef _VGS_H_
#define _VGS_H_

#include "units.h"

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 200

#define VMODE_TEXT 0x03
#define VMODE_VGA256 0x13

// COLORS
#define COLOR_BLACK 0x0
#define COLOR_BLUE 0x1
#define COLOR_GREEN 0x2
#define COLOR_CYAN 0x3
#define COLOR_RED 0x4
#define COLOR_MAGENTA 0x5
#define COLOR_BROWN 0x6
#define COLOR_LIGHT_GREY 0x7
#define COLOR_DARK_GREY 0x8
#define COLOR_LIGHT_BLUE 0x9
#define COLOR_LIGHT_GREEN 0xa
#define COLOR_LIGHT_CYAN 0xb
#define COLOR_LIGHT_RED 0xc
#define COLOR_LIGHT_MAGENTA 0xd
#define COLOR_YELLOW 0xe
#define COLOR_WHITE 0xf
#define COLOR_COUNT 0x10

typedef struct {
	word width, height;
	byte *data;
} BITMAP;

void video_setmode(byte mode);
void vga_init();
void plot_pixel(int x, int y, byte color);
void draw_bitmap(int x, int y, BITMAP *bitmap);

#endif // _VGS_H_