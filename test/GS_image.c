#include <GS/gsimage.h>

/* Let's draw a image on screen */

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("Usage : %s image file\n", argv[0]);
		printf("	for example : %s tea.png\n", argv[0]);
		exit(0);
	}
	
	gs_image ima; /* ���Ƚ��������image�Ľṹ��ַ */

	gs_image_load(argv[1], &ima); /* ����ͼ������ */
	gs_image_draw(&ima, 90, 90); /* ��  ͼ */
	gs_image_destory(&ima); /* ���ima��ͼ��������ռ���ڴ�*/
	return 0;
}

/* ����gs_image�Ľṹ�뿴gsimage.h */
/* gs_image_load(char *filepath, *gs_pimage ima); */
/* ��������ǰ�filepath��ָͼƬ��ʶ��ת������ima����ṹ���� */
/* gs_image_draw(*gs_pimage ima, x, y); */
/* ��������ǰ�ima�ڴ����ͼ�����ݣ�����������(x, y)���꿪ʼ����ͼ����Ⱦ����Ļ�� */
/* gs_image_destory(*gs_pimage ima); */
/* ��� */
