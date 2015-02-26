#include "gsfbdraw.h"

int GS_ALPHA = GS_OFF;

inline int gs_fb_draw(gs_pfb fb, int d_x, int d_y, unsigned char r, unsigned char g, unsigned char b, int a) //图像描点
{
	fb->location = d_x * fb->fb_var.bits_per_pixel / 8\
		+ d_y * fb->fb_fix.line_length;  //计算描点的坐标在内存位置
	*(fb->fb_mem + fb->location) = b;
	*(fb->fb_mem + fb->location + 1) = g;
	*(fb->fb_mem + fb->location + 2) = r;
	if (GS_ALPHA == GS_ON) //判断是否需要描alpha点
		*(fb->fb_mem + fb->location + 3) = a;
	fb->location = 0;

	return 0;
}

inline int gs_fb_draw_pos(int x, int y, unsigned char r, unsigned char g, unsigned char b, int a) //自带初始化的图像描点
{
	gs_fb fb;   
	gs_fb_init(&fb);
	gs_fb_mmap(&fb);
	gs_fb_draw(&fb, x, y, r, g, b, a);
	gs_fb_munmap(&fb);
	gs_fb_end(&fb);
	return 0;
}

inline int gs_fb_draw_rect(int x, int y, int w, int h, unsigned char r, unsigned char g, unsigned char b, int a)
{
    gs_fb fb;
    gs_fb_init(&fb);
    gs_fb_mmap(&fb);
    if (fb.fb_var.xres < x+w)
        w = fb.fb_var.xres;
    else
        w = x + w;
    if (fb.fb_var.yres < y+h)
        h = fb.fb_var.yres;
    else
        h = y + h;
    int i;
    for (; y < h; y++)
        for (i = x; i < w; i++)
            gs_fb_draw(&fb, i, y, r, g, b, a);
    gs_fb_munmap(&fb);
    gs_fb_end(&fb);
    return 0; 
}

/* 绘制一条线，包括竖直和水平两种 */
inline int gs_fb_draw_line(int x1, int y1, int x2, int y2, unsigned char r, unsigned char g, unsigned char b, int a)
{
    /* 绘制线段的斜率
     * float k = (float)(y2 - y)/(x2 - x);
     * 此功能暂时弃用,开发者自行计算曲线各点坐标
     * 使用gs_fb_draw_pos()去绘制
     */
    
    
    gs_fb fb;
    gs_fb_init(&fb);
    gs_fb_mmap(&fb);
    if (x1 == x2) {
        if (fb.fb_var.yres < y2)
            y2 = fb.fb_var.yres;
        for (; y1 <= y2; y1++)
            gs_fb_draw(&fb, x1, y1, r, g, b, a);
    }
    else {
        if (fb.fb_var.xres < x2)
            x2 = fb.fb_var.xres;
        for (; x1 <= x2; x1++)
            gs_fb_draw(&fb, x1, y1, r, g, b, a);
    }
    gs_fb_munmap(&fb);
    gs_fb_end(&fb);
    return 0;
}

/*初始化gs_fb_draw绘图组件*/
inline int gs_fb_draw_init(gs_pfb fb)
{
		gs_fb_init(fb);
		gs_fb_mmap(fb);
		return 0;
}

/*结束gs_fb_draw绘图组件*/
inline int gs_fb_draw_end(gs_pfb fb)
{
		gs_fb_munmap(fb);
		gs_fb_end(fb);
		return 0;
}

