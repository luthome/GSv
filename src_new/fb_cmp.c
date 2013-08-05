

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <linux/fb.h>
#include <asm/page.h>

typedef struct{
	char *dev;
	int fd;
	struct fb_fix_screeninfo fb_fix;
	struct fb_var_screeninfo fb_var;
	struct fb_cmap fb_map;
	long int screensize;
	long int location;
	char *fb_mem;
} gs_fb, *gs_pfb;

int gs_fb_init(gs_pfb fb)
{
	fb->dev = getenv("GS_FRAMEBUFFER");
	if (fb->dev == NULL) {
		printf("GS_ERROR : NO FB SET\n");
		exit(1);
	}
	fb->fd = open(fb->dev, O_RDWR | O_NONBLOCK);
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
	if ((ioctl(fb->fd, FBIOGETCMAP, &fb->fb_map)) == -1) {
		perror("GS_ERROR : READ SCREEN FIXED FAILED");
		exit(3);
	}
	//fb->screensize = fb->fb_var.xres * fb->fb_var.yres\
			* fb->fb_var.bits_per_pixel / 8;
	fb->screensize = (unsigned long)(fb->fb_fix.smem_start) \
		& (~PAGE_MASK) + fb->fb_fix.smem_len;
	
	return 1;
}

void gs_fb_end(gs_pfb fb)
{
	close(fb->fd);
	fb->fd = -1;
	fb->screensize = 0;
	fb->fb_mem = NULL;
	fb->location = 0;
}
int gs_fb_mmap(gs_pfb fb)
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
	
	return 1;
}


void gs_fb_munmap(gs_pfb fb)
{
	munmap(fb->fb_mem, fb->screensize);
	fb->fb_mem = NULL;
}


int main(void)
{
	gs_fb h;
	gs_fb_init(&h);
	gs_fb_mmap(&h);
	gs_fb_munmap(&h);
	gs_fb_end(&h);

	return 0;
}


