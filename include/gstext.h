#ifndef _GSTEXT_H_
#define _GSTEXT_H_

typedef struct{
	int x, y;
	char *text;
	char *size;
	char *color;
} gs_text, *GS_TEXT;

extern int GS_View_Text(GS_TEXT text, int x, int y);

#endif
