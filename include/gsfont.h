#ifndef _GSFONT_H_
#define _GSFONT_H_




extern void gs_put_char(int x, int y, int c, char *color);
extern void gs_put_char_rgb(int x, int y, int c, unsigned char r, unsigned char g, unsigned char b);
extern void gs_put_string(int x, int y, char *s, char *color);
extern void gs_put_string_center(int x, int y, char *s, char *color);



#endif



