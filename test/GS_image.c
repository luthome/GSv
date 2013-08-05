#include <GS/gsimage.h>

/* Let's draw a image on screen */

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("Usage : %s image file\n", argv[0]);
		printf("	for example : %s tea.png\n", argv[0]);
		exit(0);
	}
	
	gs_image ima; /* 首先建立个存放image的结构地址 */

	gs_image_load(argv[1], &ima); /* 载入图像数据 */
	gs_image_draw(&ima, 90, 90); /* 画  图 */
	gs_image_destory(&ima); /* 清除ima内图像数据所占的内存*/
	return 0;
}

/* 具体gs_image的结构请看gsimage.h */
/* gs_image_load(char *filepath, *gs_pimage ima); */
/* 这个函数是把filepath所指图片，识别，转换存入ima这个结构体内 */
/* gs_image_draw(*gs_pimage ima, x, y); */
/* 这个函数是把ima内存入的图像数据，按照所给的(x, y)坐标开始，将图像渲染到屏幕上 */
/* gs_image_destory(*gs_pimage ima); */
/* 清除 */
