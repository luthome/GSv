#include <stdio.h>
#include <GS/gsfbdraw.h>

/* Let's draw a block on screen! */

/*
 * :)	
 */
 
 
int main(void)
{
	gs_fb_draw_block(280, 200, 190, 189, 208, 67);
	return 0;
}



/* API HELP! */
/* The gs_fb_draw_block() function is draw a block on screen */
/* gs_fb_draw_block(x, y, r, g, b, a); */
/* x 代表要画矩形的宽 */
/* y 代表要画矩形的高 */
/* r 矩形填充的red色值 */
/* g green */
/* b blue */
/* a alpha 透明度*/
