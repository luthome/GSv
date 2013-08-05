#include "gsfbdraw.h"

int gs_fb_draw(gs_pfb fb, int d_x, int d_y, int r, int g, int b, int a)
{
	fb->location = d_x * fb->fb_var.bits_per_pixel / 8\
		+ d_y * fb->fb_fix.line_length;
	*(fb->fb_mem + fb->location) = b;
	*(fb->fb_mem + fb->location + 1) = g;
	*(fb->fb_mem + fb->location + 2) = r;
	if (a != NULL)
		*(fb->fb_mem + fb->location + 3) = a;
	fb->location = 0;

	return 1;
}

int gs_fb_draw_block(int d_x, int d_y, int r, int g, int b,int a)
{
	gs_fb fb;
	gs_fb_init(&fb);
	int ss_x = fb.fb_var.xres / 2 - d_x / 2;
	int se_x = fb.fb_var.xres / 2 + d_x / 2;
	const int const_x = ss_x;
	int ss_y = fb.fb_var.yres / 2 - d_y / 2;
	int se_y = fb.fb_var.yres / 2 + d_y / 2;
	gs_fb_mmap(&fb);
	for(ss_y; ss_y <= se_y; ss_y++) {
		for(ss_x = const_x; ss_x <= se_x; ss_x++) {
			gs_fb_draw(&fb, ss_x, ss_y, r, g, b, a);
		}
	}
	gs_fb_munmap(&fb);
	gs_fb_end(&fb);
	return 1;
}

int gs_fb_draw_pos(int x, int y, int r, int g, int b, int a)
{
	gs_fb fb;
	gs_fb_init(&fb);
	gs_fb_mmap(&fb);
	gs_fb_draw(&fb, x, y, r, g, b, a);
	gs_fb_munmap(&fb);
	gs_fb_end(&fb);
	return 0;
}



