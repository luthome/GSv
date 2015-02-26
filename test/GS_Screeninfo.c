#include <GS/gsfb.h>
#include <stdio.h>
 
/* ��Ļ��Ϣ�ĵõ� */ 
 
int main(void)
{
    gs_fb myscreen;
    gs_fb_init(&myscreen);
    
    printf("\nMy Screen info:\n");
    printf("\tSize: %d x %d\n", myscreen.fb_var.xres, myscreen.fb_var.yres);
    printf("\tColor depth: %d", myscreen.fb_var.bits_per_pixel);
    printf("\n");
    printf("If you want to know more info for your machine's screen\n");
    printf("the gs_fb structure will help you. (see in gsfb.h)\n");
    printf("  :-)  \n");
    
    gs_fb_end(&myscreen);
    return 0;
}

/* gs_fb ������Ļ�ṹ */
/* gs_fb_init(gs_pfb fb)��ʼ��fb��Ϣ��������Ļ��Ϣ��fb�� */
/* gs_fb_end(gs_pfb fb) ���fb��������ռ�ڴ� */ 
