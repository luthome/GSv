#ifndef _GSIMAGE_H_
#define _GSIMAGE_H_

#include "gsfb.h"

typedef struct{
	int image_type;
	int channels;
	int width;
	int height;
	int bit_depth;
	int color_type;
	int have_alpha;
	int *rgba[4];
} gs_image, *gs_pimage;


extern int gs_image_load(char *filepath, gs_pimage ima);
extern int gs_image_load_png(char *filepath, gs_pimage ima);
//extern int gs_image_load_jpeg(char *filepath, gs_pimage ima);
extern int gs_image_create(gs_pimage ima);
extern int gs_image_draw(gs_pimage ima, int s_x, int s_y);
extern int gs_image_destory(gs_pimage ima);

#endif
