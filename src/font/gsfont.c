#include <stdio.h>
#include <string.h>
#include "gsfbdraw.h"
#include "gstools.h"
#include "font.h"
#include "gsfont.h"




//get from internet

//(x, y)get location, c = char, *color = color val
void gs_put_char(int x, int y, int c, char *color)
{
    int i, j, bits;
    unsigned char r, g, b;
    
    gs_get_color(color, &r, &g, &b);

    for (i = 0; i < font_vga_8x8.height; i++) {
        bits = font_vga_8x8.data[font_vga_8x8.height * c + i];
        for (j = 0; j < font_vga_8x8.width; j++, bits <<= 1)
            if (bits & 0x80)
                gs_fb_draw_pos(x + j, y + i, r, g, b, 0);
    }
}

void gs_put_char_rgb(int x, int y, int c, unsigned char r, unsigned char g, unsigned char b)
{
    int i, j, bits;
    

    for (i = 0; i < font_vga_8x8.height; i++) {
        bits = font_vga_8x8.data[font_vga_8x8.height * c + i];
        for (j = 0; j < font_vga_8x8.width; j++, bits <<= 1)
            if (bits & 0x80)
                gs_fb_draw_pos(x + j, y + i, r, g, b, 0);
    }
}

void gs_put_string(int x, int y, char *s, char *color)
{
    int i;
    unsigned char r, g, b;

    gs_get_color(color, &r, &g, &b);
    for (i = 0; *s; i++, x += font_vga_8x8.width, s++)
        gs_put_char_rgb(x, y, *s, r, g, b);
}

void gs_put_string_center(int x, int y, char *s, char *color)
{
    size_t sl = strlen(s);
    gs_put_string(x - (sl/2) * font_vga_8x8.width,
                y - font_vga_8x8.height / 2, s, color);
}


