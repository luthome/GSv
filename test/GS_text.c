#include <GS/gsfb.h>
#include <GS/gsfbdraw.h>
#include <GS/gsfont.h>
#include <GS/font.h>

extern struct fbcon_font_desc font_vga_8x8;
int main()
{
    gs_fb fb;
    gs_fb_init(&fb);

    gs_fb_draw_rect(0, 0, fb.fb_var.xres, fb.fb_var.yres, 255, 34, 43, 0);
    
    //gs_put_string_center(20, 30, "welcome to the TEXT about GS world", "E8E8F2");
    
    /*
     * a example about gs_put_string_center() function.
     * 
     * 
static void button_draw (struct ts_button *button)
{
	int s = (button->flags & BUTTON_ACTIVE) ? 3 : 0;
	rect (button->x, button->y, button->x + button->w - 1,
	      button->y + button->h - 1, button_palette [s]);
	fillrect (button->x + 1, button->y + 1,
		  button->x + button->w - 2,
		  button->y + button->h - 2, button_palette [s + 1]);
	put_string_center (button->x + button->w / 2,
			   button->y + button->h / 2,
			   button->text, button_palette [s + 2]);
}
	*
	* 
	*/
	int i = 100000;
    while (i) {
	gs_put_string(20, 30, "Hello World", "E8E8F2");
	gs_put_string(20, 50, "\nThis is GS Text mod", "E8E8F2");
    i--;
    }
    gs_fb_end(&fb);
    return 0;
}
