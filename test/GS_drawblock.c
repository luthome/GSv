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
/* x ����Ҫ�����εĿ� */
/* y ����Ҫ�����εĸ� */
/* r ��������redɫֵ */
/* g green */
/* b blue */
/* a alpha ͸����*/
