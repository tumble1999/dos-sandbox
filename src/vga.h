#ifndef _VGS_H_
#define _VGS_H_

#include "units.h"

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 200

#define VMODE_TEXT 0x03
#define VMODE_VGA256 0x13

typedef struct tagBITMAP /* the structure for a bitmap. */
{
	word width;
	word height;
	byte palette[256 * 3];
	byte *data;
} BITMAP;

void video_setmode(byte mode);
void vga_init();
void plot_pixel(int x, int y, byte color);
void draw_bitmap(int x, int y, BITMAP *bitmap);

#endif // _VGS_H_