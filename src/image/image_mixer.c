#include "gsimage.h"

//透过透明图像Ａ看到底层的图像Ｂ
//得到Ａ和Ｂ的混合图像Ｃ

gs_pimage gs_image_mixer(gs_pimage a, gs_pimage b)
{
    int i, j;
    int width = a->width;
    int heigh = a->height;
    gs_pimage c;
    c->channels = 3;
    gs_image_create(c);
    //gs_pimage p = &c;
    for (j = 0; j < heigh; j++) {
        for (i = 0; i < width; i++) {
            c->rgba[0][i+j*width] = a->rgba[0][i+j*width] * (100-a->rgba[3][i+j*width])\
                                       + b->rgba[3][i+j*width] * b->rgba[0][i+j*width];
            c->rgba[1][i+j*width] = a->rgba[1][i+j*width] * (100-a->rgba[3][i+j*width])\
                                       + b->rgba[3][i+j*width] * b->rgba[1][i+j*width];
            c->rgba[2][i+j*width] = a->rgba[2][i+j*width] * (100-a->rgba[3][i+j*width])\
                                       + b->rgba[3][i+j*width] * b->rgba[2][i+j*width];
        }
    }
    return c;
}
