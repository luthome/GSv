#ifndef _GSWINDOW_H_
#define _GSWINDOW_H_

typedef struct button{
    int x, y;
    char *size;
    char *text_color;
    char *back_color;
    char *frame_color;
    char *text;
} gs_button, *gs_pbutton;

typedef struct window{
    int x, y;
    char *size;
    char *text_color;
    char *back_color;
    char *frame_color;
    char *img;
    char *text;
    struct button *button;
} gs_window, *gs_pwindow;

/* draw a window */
extern int gs_show_window(struct window *win);

/* draw a button */
extern int gs_show_button(struct button *but);

/* 绘制一个从(x, y)坐标开始，size大小矩形的边框 */
/* 请注意边框是否越界 */
extern int gs_rect_frame(int x, int y, char *size, char *color);

#endif
