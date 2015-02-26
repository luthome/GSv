
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
//#include <asm/page.h>
#include "gsfb.h"

int gs_fb_init(gs_pfb fb)  //初始化gs_fb的组件
{
	fb->dev = getenv("GS_FB"); //得到framebuffer所在址
	if (fb->dev == NULL) {
		printf("GS_ERROR : NO FB SET\n");
		exit(1);
	}
	fb->fd = open(fb->dev, O_RDWR | O_NONBLOCK); //打开FB设备，得到文件描述符
	if (fb->fd == -1) {
		perror("GS_ERROR : OPEN FB DEVICE FAILED");
		exit(2);
	}
	if ((ioctl(fb->fd, FBIOGET_FSCREENINFO, &fb->fb_fix)) == -1) {
		perror("GS_ERROR : READ SCREEN FIXED FAILED");
		exit(3);
	}
	if ((ioctl(fb->fd, FBIOGET_VSCREENINFO, &fb->fb_var)) == -1) {
		perror("GS_ERROR : READ SCREEN VARIBLE FAILED");
		exit(3);
	}
	fb->screensize = fb->fb_var.xres * fb->fb_var.yres\
			* fb->fb_var.bits_per_pixel / 8;
	//fb->screensize = (unsigned long)(fb->fb_fix.smem_start) \
		& (~PAGE_MASK) + fb->fb_fix.smem_len;
	
	return 0;
}

int gs_fb_mmap(gs_pfb fb)  //射映fb设备到内存
{
	//fb->fb_mem_offset = (unsigned long)(fb->fb_fix.smem_start) \
		& (~PAGE_MASK); 
	fb->fb_mem =mmap(NULL, \
		fb->screensize,\
		PROT_READ | PROT_WRITE, MAP_SHARED,\
		fb->fd, 0);
	if ((int)fb->fb_mem == -1) {
		perror("GS_ERROR : MMAP FB DEVICE TO RAM FAILED");
		gs_fb_end(fb);
		exit(4);
	}
	
	return 0;
}

void gs_fb_end(gs_pfb fb)  //销毁对fb打开的文件描述符等
{
	close(fb->fd);
	fb->fd = -1;
	fb->screensize = 0;
	fb->fb_mem = NULL;
	fb->location = 0;
}

void gs_fb_munmap(gs_pfb fb) //解除fb的射映
{
	munmap(fb->fb_mem, fb->screensize);
	fb->fb_mem = NULL;
}

/*   This for GS
void GSClear_Screen(void)
{
	gs_fb fb;
	gs_fb_init(&fb);
	gs_fb_mmap(&fb);
	memset(fb.fb_mem, 0, fb.fb_var.xres * fb.fb_var.yres * fb.fb_var.bits_per_pixel / 8);
	gs_fb_munmap(&fb);
	gs_fb_end(&fb);
}
*/



