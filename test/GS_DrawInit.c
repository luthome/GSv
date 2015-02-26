#include <GS/gsfbdraw.h>

int main()
{
		int x = 0, y = 0;
		gs_fb myfb;

		gs_fb_init(&myfb);
		gs_fb_mmap(&myfb);

		GS_ALPHA = GS_OFF;

		while (1) {
		for (y = 0; y < 240; y++) {
				for (x = 0; x < 320; x++)
					gs_fb_draw(&myfb, x, y , 50, 60, 70, 0);
		}
		}

		gs_fb_munmap(&myfb);
		gs_fb_end(&myfb);
		return 0;
}
		

