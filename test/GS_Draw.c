#include <GS/gsfbdraw.h>

int main()
{
		int x = 0, y = 0;
		gs_fb myfb;
		gs_fb_init(&myfb);

		int fx = myfb.fb_var.xres;
		int fy = myfb.fb_var.yres;

		gs_fb_draw_init(&myfb);
while(1) {
		for (y = 0; y < fy; y++) {
				for (x = 0; x < fx; x++)
					gs_fb_draw(&myfb, x, y , 50, 60, 70, 0);
		}
}
		return 0;
}
		

