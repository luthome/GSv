#ifndef _GSFBDRAW_H_
#define _GSFBDRAW_H_

#include "gsfb.h"

extern int GS_ALPHA;

//绘制(x, y)坐标一个点，绘制在指定的fb上
extern int gs_fb_draw(gs_pfb fb, int d_x, int d_y, unsigned char r, unsigned char g, unsigned char b, int a);

//绘制(x, y)坐标一个点，颜色r,g,b,a
extern int gs_fb_draw_pos(int x, int y, unsigned char r, unsigned char g, unsigned char b, int a);

//绘制从(x, y)开始宽w,高h的矩形,颜色r,g,b,a
extern int gs_fb_draw_rect(int x, int y, int w, int h, unsigned char r, unsigned char g, unsigned char b, int a);

//绘制从(x1, y1)到(x2, y2)的线段,颜色r,g,b,a
extern int gs_fb_draw_line(int x1, int x2, int y1, int y2, unsigned char r, unsigned char g, unsigned char b, int a);

//初始化gs_fb_draw绘图组件
extern int gs_fb_draw_init(gs_pfb fb);

//结束gs_fb_draw组件
extern int gs_fb_draw_end(gs_pfb fb);

#endif
