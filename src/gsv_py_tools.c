#include <stdio.h>
#include "gsfb.h"

void get_gsfb_str(void *get_str)
{
	get_str = NULL;
	gs_pfb get_str_tmp;
	get_str = get_str_tmp;
	if (get_str == NULL)
		printf("get gs_fb struct failed!\n");
	else
		printf("get gs_fb struct successed!\n");
}
