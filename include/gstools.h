#ifndef _GSTOOLS_H_
#define _GSTOOLS_H_

//从十六进制字符串中获取r,g,b各颜色的十进制数值
extern void gs_get_color(char *pcolor, unsigned char *r, unsigned char *g, unsigned char *b);

//大小字符串"***X***" || "***x***"中获取前后两分量值
extern void gs_get_size(char *size, int *op1, int *op2);

#endif
