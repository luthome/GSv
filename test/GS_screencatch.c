#include <GS/gsfb.h>
#include <GS/gsimage.h>

int main()
{

	gs_image in_img,out_img;
	gs_fb fb;
	gs_fb_init(&fb);
	gs_fb_mmap(&fb);
	in_img.width = fb.fb_var.xres;
	in_img.height = fb.fb_var.yres;
	in_img.bit_depth = fb.fb_var.bits_per_pixel;
	
	in_img.rgba[0] = malloc(in_img.width*in_img.height*4);
	in_img.rgba[1] = malloc(in_img.width*in_img.height*4);
	in_img.rgba[2] = malloc(in_img.width*in_img.height*4);
	in_img.rgba[3] = malloc(in_img.width*in_img.height*4);
	
	int d_x = 0, d_y = 0, pos = 0;
	for (; d_y < in_img.height; d_y++) {
		for (d_x = 0; d_x < in_img.width; d_x++) {
			fb.location = d_x * fb.fb_var.bits_per_pixel / 8\
				+ d_y * fb.fb_fix.line_length;  //计算描点的坐标在内存位置
			in_img.rgba[2][pos]=*(fb.fb_mem + fb.location); //b;
			in_img.rgba[1][pos]=*(fb.fb_mem + fb.location + 1); //g;
			in_img.rgba[0][pos]=*(fb.fb_mem + fb.location + 2); //r;
			//if (GS_ALPHA == GS_ON) //判断是否需要描alpha点
			in_img.rgba[3][pos]=*(fb.fb_mem + fb.location + 3); //a;
			pos++;
		}
	}
	//for (d_y = 0, pos = 0; d_y < in_img.height; d_y++) {
//		for (d_x = 0; d_x < in_img.width; d_x++) {
//			printf(" {%d, %d, %d, %d} ", in_img.rgba[0][pos],
//				in_img.rgba[1][pos],
//				in_img.rgba[2][pos],
//				in_img.rgba[3][pos]);
//				pos++;
//		}
//		printf("\n");
//	}
	free(in_img.rgba[0]);
	free(in_img.rgba[1]);
	free(in_img.rgba[2]);
	free(in_img.rgba[3]);
	
	printf("\nwidth=%d, height=%d\n", in_img.width, in_img.height);
	
	return 0;
}
