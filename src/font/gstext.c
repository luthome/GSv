#include "gsfont.h"
#include "gstext.h"

int GS_View_Word(GS_TEXT text, char *word, int x, int y)
{
	draw_font a;
	a.word = word;
	if (text->size == NULL)
		a.size =  10; //atoi(getenv("GS_FONTSIZE"));
	else
		a.size = atoi(text->size);
	scan_word(&a);
	draw_word(&a, x, y);
	text->x = a.ex + 2;
	text->y = a.y;
	destory_word(&a);
	return 0;
}

int GS_View_Text(GS_TEXT text, int x, int y)
{
	char step;
	step = *text->text;
	while (step != '\0') {
		step = *text->text++;
		GS_View_Word(text, &step, x, y);
		x = text->x;
		y = text->y;
	}
	return 0;
}
