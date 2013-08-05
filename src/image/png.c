#include <png.h>
#include <stdlib.h>
#include "gsfbdraw.h"
#include "gsimage.h"

int gs_image_load_png(char *filepath, gs_pimage ima)
/* 载入PNG图片中的图形数据 */
{
	FILE *pic_fp;
	pic_fp = fopen(filepath, "rb");
	if(pic_fp == NULL) {/* 文件打开失败 */
		printf("CANNOT OPEN FILE\n");
		return 1;
	}
	
	/* 初始化各种结构 */
	png_structp png_ptr;
	png_infop   info_ptr;
	int         i, j, temp, pos;
	
	png_ptr  = png_create_read_struct(PNG_LIBPNG_VER_STRING, 0, 0, 0);
	info_ptr = png_create_info_struct(png_ptr);
	
	setjmp(png_jmpbuf(png_ptr)); /* 这句很重要 */
	
	//ERROR ima->type = "PNG";
	
	rewind(pic_fp);
	/* 开始读文件 */
	png_init_io(png_ptr, pic_fp); 
	png_read_png(png_ptr, info_ptr, PNG_TRANSFORM_EXPAND, 0);

	/*获取宽度，高度，位深，颜色类型*/
	ima->channels       = png_get_channels(png_ptr, info_ptr);/*获取通道数*/
	ima->bit_depth = png_get_bit_depth(png_ptr, info_ptr);
	ima->color_type  = png_get_color_type(png_ptr, info_ptr);/*颜色类型*/
	
	/* row_pointers里边就是rgba数据 */
	png_bytep* row_pointers;
	row_pointers = png_get_rows(png_ptr, info_ptr);
	
	ima->image_type = 6;  /* 图片类型为png */
		ima->width = png_get_image_width(png_ptr, info_ptr); 
		ima->height = png_get_image_height(png_ptr, info_ptr);
	if (ima->color_type == PNG_COLOR_TYPE_RGB_ALPHA) 
		ima->have_alpha = 1;
	else
		ima->have_alpha = 0;
	if(ima->channels == 4 || ima->color_type == PNG_COLOR_TYPE_RGB_ALPHA) {
	/*如果是RGB+alpha通道，或者RGB+其它字节*/
		temp = (4 * ima->width);
		/* 开始分配内存 */
		gs_image_create(ima);
		for(pos = 0, i=0; i < ima->height; i++) {
			for(j=0; j < temp; j += 4) {
				ima->rgba[0][pos] = row_pointers[i][j];// red
				ima->rgba[1][pos] = row_pointers[i][j+1];// green
				ima->rgba[2][pos] = row_pointers[i][j+2];// blue
				ima->rgba[3][pos] = row_pointers[i][j+3];// alpha
				pos++;
			}
		}
	}	
	else if(ima->channels == 3 || ima->color_type == PNG_COLOR_TYPE_RGB) {
	/*如果是RGB通道*/
		temp = (3 * ima->width);
		/* 开始分配内存 */
		gs_image_create(ima);
		for(pos=0,i=0; i < ima->height; i++)
			for(j=0; j < temp; j += 3) {
				ima->rgba[0][pos] = row_pointers[i][j];// red
				ima->rgba[1][pos] = row_pointers[i][j+1];// green
				ima->rgba[2][pos] = row_pointers[i][j+2];// blue
				++pos;
			} 
		} else {
		return 1;
	}
	/* 撤销数据占用的内存 */
	png_destroy_read_struct(&png_ptr, &info_ptr, 0);
	return 0;
}





