#ifndef _GSFBDRAW_H_
#define _GSFBDRAW_H_

#include "gsfb.h"
/*
typedef struct drawfb {
	int d_x, d_y;
	char *d_alpha, *d_red, *d_green, *d_blue;
} draw_fb, *draw_pfb;
*/
//int gs_fb_draw(gs_pfb fb, int d_x, int d_y, int r, int g, int b,int a);
extern int gs_fb_draw_block(int d_x, int d_y, int r, int g, int b,int a);
extern int gs_fb_draw(gs_pfb fb, int d_x, int d_y, int r, int g, int b, int a);
extern int gs_fb_draw_pos(int x, int y, int r, int g, int b, int a);

#endif
