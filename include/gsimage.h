#ifndef _GSIMAGE_H_
#define _GSIMAGE_H_

#include "gsfb.h"
#define GS_PNG 1000000 //png图像类型的编号

typedef struct{
	int image_type;
	int channels; //通道数目
	int width; //宽
	int height; //高
	int bit_depth; //位深
	int color_type; //颜色类型
	int have_alpha; //是否有alpha值
	int *rgba[4]; //red, green, blue, alpha的各点矩阵值
} gs_image, *gs_pimage;

/*
 * 向一个gs_pimage图像数据中载入一个图像数据
 * filetype图像类型:png, jpeg, bmp等
 * filepath要载入的图像文件目录地址
 */
extern int gs_image_load(int filetype, char *filepath, gs_pimage ima);


//extern int gs_image_load_png(char *filepath, gs_pimage ima);
//extern int gs_image_load_jpeg(char *filepath, gs_pimage ima);

/*
 * 创建一个gs_pimage图像数据结构
 */
extern int gs_image_create(gs_pimage ima);

/*
 * 绘制gs_pimage储存的图像，从(x, y)坐标开始绘制
 */
extern int gs_image_draw(gs_pimage ima, int s_x, int s_y);

/*
 * 销毁一个gs_pimage图像数据
 */
extern int gs_image_destory(gs_pimage ima);

/*
 * 透过透明图像Ａ看底层图像Ｂ
 * 返回一个Ａ和Ｂ的混合图像Ｃ
 * return (gs_pimage)c
 */
extern gs_pimage gs_image_mixer(gs_pimage a, gs_pimage b);

#endif
