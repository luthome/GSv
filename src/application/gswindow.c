#include <stdio.h>
#include <stdlib.h>
#include "gsfb.h"
#include "gsfbdraw.h"
#include "gstools.h"
#include "gsfont.h"
#include "gswindow.h"



int gs_show_button(struct button *but);
int gs_rect_frame(int x, int y, char *size, char *color);

/* just a example
 * 
 * *********************************************************************
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
    a.color = "FFFFFF";

    int width, heigh;
    gs_get_size(a.size, &width, &heigh);

	a.button = (struct button *)malloc(sizeof(struct button));
	//initlizatied button struct
    a.button->x = 20;
    a.button->y = 30;
    a.button->size = "120x40";
    a.button->text = "yes";
    a.button->color = "E8E8E8";



    //初始化全屏幕
    gs_fb_draw_rect(0, 0, x, y, 255, 34, 43, 0);

	
	gs_show_window(&a);

    return 0;
}
* **********************************************************************
*/

int gs_show_window(struct window *win)
{
	unsigned char b_r, b_g, b_b;
    int width, heigh;
    
    gs_get_color(win->back_color, &b_r, &b_g, &b_b);
	gs_get_size(win->size, &width, &heigh);
	
	//绘制窗口边框
    gs_rect_frame(win->x, win->y, win->size, win->frame_color); //边框采用纯黑色
    //填充窗口图像
    gs_fb_draw_rect(win->x, win->y, width, heigh, b_r, b_g, b_b, 0);
    
    //put window text
    gs_put_string_center(win->x + width / 2,
						win->y + heigh / 2,
						win->text, win->text_color);
	

	//if (win->button != 0)
	//绘制按钮
    //gs_show_button(win->button->x + win->x, win->button->y + win->y, win->button);
	
	return 0;
}

int gs_show_button(struct button *but)
{
    int x = but->x, y = but->y;
    unsigned char b_r, b_g, b_b;
    int width, heigh;

    gs_get_color(but->back_color, &b_r, &b_g, &b_b);
    gs_get_size(but->size, &width, &heigh);


    //先描绘按钮边框
    gs_rect_frame(x, y, but->size, but->frame_color); //边框采用纯黑色

    //填充按钮内部
    gs_fb_draw_rect(x, y, width, heigh, b_r, b_g, b_b, 0);
    

    //put button text
    gs_put_string_center(x + width / 2,
						y + heigh / 2,
						but->text, but->text_color);


    return 0;
}

/* 绘制一个从(x, y)坐标开始，size大小矩形的边框 */
/* 请注意边框是否越界 */
int gs_rect_frame(int x, int y, char *size, char *color)
{
    int width, heigh;
    unsigned char r, g, b;

    gs_get_color(color, &r, &g, &b);
    gs_get_size(size, &width, &heigh);

    //描绘边框的四条线
    gs_fb_draw_line(x-1, y-1, x+width, y-1, r, g, b, 0);
    gs_fb_draw_line(x-1, y-1, x-1, y + heigh, r, g, b, 0);
    gs_fb_draw_line(x-1, y+heigh, x+width, y+heigh, r, g, b, 0);
    gs_fb_draw_line(x+width, y-1, x+width, y + heigh, r, g, b, 0);

    return 0;
}
