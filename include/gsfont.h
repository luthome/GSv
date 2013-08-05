#ifndef _GSFONT_H_
#define _GSFONT_H_

#include <ft2build.h>
#include <freetype/freetype.h>
#include <freetype/ftglyph.h>

typedef struct font{
	char *word;
	int x, y, ex, ey;
	FT_Error FT_error;
	FT_BitmapGlyph FT_bitmap_glyph;
	FT_Bitmap FT_bitmap;
	FT_Glyph FT_glyph;
	FT_Library FT_Lib;
	FT_Face FT_Face;
} draw_font, *Draw_Font;

extern int scan_word(Draw_Font word, int size);
extern int draw_word(Draw_Font word, int x, int y);
extern int destory_word(Draw_Font word);

#endif
