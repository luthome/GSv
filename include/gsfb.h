#ifndef _GSFB_H_
#define _GSFB_H_

#include <linux/fb.h>

#define GS_ON 1
#define GS_OFF 0
#define GS_FAILED  1
#define GS_SUCCESSD 0

typedef struct gsfb{
	int fd;
	char *dev;
	char *fb_mem;
	unsigned long  screensize;
	long int location;
	struct fb_fix_screeninfo fb_fix;
	struct fb_var_screeninfo fb_var;
} gs_fb, *gs_pfb;

extern int gs_fb_init(gs_pfb fb);
extern void gs_fb_end(gs_pfb fb);
extern int gs_fb_mmap(gs_pfb fb);
extern void gs_fb_munmap(gs_pfb fb);
extern void GSClear_Screen(void);
#endif
