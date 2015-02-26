#include <stdlib.h>
#include "gsfb.h"
#include "gsfbdraw.h"
#include "gsimage.h"

       
extern int gs_image_load(int filetype, char *filepath, gs_pimage ima)
{
	int result;

	if(filetype == GS_PNG)
			result = gs_image_load_png(filepath, ima);
	//if(filetype == "jpg")
	//		result = gs_image_load_jpg(filepath, ima);
	//if(filetype == "bmp")
	//		result = gs_image_load_bmp(filepath, ima);
	if (result != 0)
		printf("[gs_image_load] : failed!\n");
	return 0;
}

int gs_image_create(gs_pimage ima)
{
	int ram = ima->width * ima->height * 4;
	ima->rgba[0] = malloc(ram);
	ima->rgba[1] = malloc(ram);
	ima->rgba[2] = malloc(ram);
	if (ima->channels == 4)
		ima->rgba[3] = malloc(ram);
	return 1;
}

int gs_image_destory(gs_pimage ima)
{
	free(ima->rgba[0]);
	free(ima->rgba[1]);
	free(ima->rgba[2]);
	if (ima->channels == 4)
		free(ima->rgba[3]);
	ima->width = 0;
	ima->height = 0;
	ima->bit_depth = 0;
	ima->color_type = 0;
	ima->channels = 0;
	return 1;
}

int gs_image_draw(gs_pimage ima, int s_x, int s_y){
	gs_fb fb;
	gs_fb_init(&fb);
	gs_fb_mmap(&fb);
	const sc_x = s_x;
	const sc_y = s_y;
	int pos = 0;
	if (ima->channels == 4 && ima->have_alpha == 1) {
		for (s_y; s_y < (sc_y + ima->height); s_y++) {
			for (s_x = sc_x; s_x < (sc_x + ima->width); s_x++, pos++) {
				gs_fb_draw(&fb, s_x, s_y, ima->rgba[0][pos], ima->rgba[1][pos], ima->rgba[2][pos], ima->rgba[3][pos]);
			}
		}
	}
	if (ima->channels == 3 || ima->have_alpha == 0) {
		for (s_y; s_y < (sc_y + ima->height); s_y++) {
			for (s_x = sc_x; s_x < (sc_x + ima->width); s_x++, pos++) {
				gs_fb_draw(&fb, s_x, s_y, ima->rgba[0][pos], ima->rgba[1][pos], ima->rgba[2][pos], GS_OFF);
			}
		}
	}
	gs_fb_munmap(&fb);
	gs_fb_end(&fb);
	return 1;
}
