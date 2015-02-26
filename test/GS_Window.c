#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <GS/gsfb.h>
#include <GS/gstools.h>
#include <GS/gsfbdraw.h>
#include <GS/gswindow.h>

int main()
{
    gs_fb fb;

    gs_fb_init(&fb);
    int x = fb.fb_var.xres;
    int y = fb.fb_var.yres;
    printf("my screen width:%d\t heigh=%d\n", x, y);
    gs_fb_end(&fb);


    //unsigned char r, g, b;
    //unsigned char r2, g2, b2;


    gs_window a;
 
	memset(&a, 0, sizeof(struct window));
 
    a.x = 20;
    a.y = 30;
    a.size = "320x240";
    a.text = "welcome GS word";
    a.back_color = "FFFFFF";
    a.frame_color = "000000";
    a.text_color = "E8E8E8";

    int width, heigh;
    gs_get_size(a.size, &width, &heigh);

	a.button = (struct button *)malloc(sizeof(struct button));
	//initlizatied button struct
    a.button->x = 20 + a.x;
    a.button->y = 30 + a.y;
    a.button->size = "120x40";
    a.button->text = "yes";
    a.button->back_color = "FFFFFF";
    a.button->frame_color = "000000";
    a.button->text_color = "E8E8E8";

    gs_button button1;
    button1.x = 20 + 120 + 40 + a.x;
    button1.y = 30 + a.y;
    button1.size = "120x40";
    button1.text = "no";
    button1.text_color = "E3DF32";
    button1.back_color = "FFFFFF";
    button1.frame_color = "000000";



    //初始化全屏幕
    gs_fb_draw_rect(0, 0, x, y, 255, 34, 43, 0);

	
	gs_show_window(&a);
    gs_show_button(a.button);
    gs_show_button(&button1);

    return 0;
}
