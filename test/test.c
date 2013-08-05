#include "gsfb.h"
#include "gsimage.h"
#include <stdio.h>
#include <string.h>
#include <memory.h>

int GS_Init(void)
{
	gs_fb sceen;
	gs_fb_init(&sceen);
	gs_fb_mmap(&sceen);
	memset(sceen.fb_mem, '0', sceen.fb_var.xres * sceen.fb_var.yres); 
	gs_fb_munmap(&sceen);
	gs_fb_end(&sceen);
	return 0;
}	

int main(int argc, char *argv[])
{
	GS_Init();
	gs_image ima, b;
	int x = 0, y = 0;
	gs_image_load(argv[1], &ima);
	gs_image_load(argv[2], &b);
	for (x = 0, y = 0; x < 320 && y < 240; ++x, ++y) {
	gs_image_draw(&ima, 0, 0);
	gs_image_draw(&b, x, y);
	}
	gs_image_destory(&ima);
	gs_image_destory(&b);
	return 0;
}
