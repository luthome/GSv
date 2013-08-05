#include <iconv.h>
#include <memory.h>
#include "gsfont.h"

int UTF8_UNICODE(char* pInput, char** ppOutput)  // UTF8转UNICODE
{
	int outputSize = 0;
	*ppOutput = (char*)malloc(strlen(pInput) * 2); 
	memset(*ppOutput,0, strlen(pInput) * 2);
	char *tmp =*ppOutput;
  
	while (*pInput) {
		if ((*pInput >= 0x00 && *pInput < 0x7f)) {  
		*tmp = *pInput;
		tmp++;
		*tmp = 0;
                        } else if (((*pInput) & 0xE0)== 0xC0) {
                                      char high = *pInput;
                                      pInput++;
                                      char low = *pInput;
                                      if ((low & 0xC0) != 0x80) {
                                                    return-1;
                                      }
      
                                      *tmp = (high << 6) +(low & 0x3F);
                                      tmp++;
                                      *tmp = (high >> 2) &0x07;
                        } else if (((*pInput) & 0xF0)== 0xE0) {
                                      char high = *pInput;
                                      pInput++;
                                      char middle =*pInput;
                                      pInput++;
                                      char low = *pInput;
                                       if (((middle & 0xC0) != 0x80) || ((low & 0xC0) != 0x80)) {
                                                     return -1;
                                       }
                                       *tmp = (middle << 6) + (low & 0x7F);
                                       tmp++;
                                       *tmp = (high << 4)+ ((middle >> 2) & 0x0F);  
                      } else {
                                       return -1;
                     }
                     pInput++;
                     tmp ++;
                     outputSize += 2;
            }
            *tmp = 0;
            tmp++;
            *tmp = 0;
            return outputSize;
}
char *GB2312_UTF8(char*str)  // GB2312转UTF8
{
            unsigned int src_len = strlen(str);
            unsigned char dst[256] = {0};
            unsigned int dst_len = sizeof(dst);
            const unsigned char* in = (unsigned char*)str;
            unsigned char* out = dst;
     
            iconv_t cd = iconv_open("UTF-8","GB2312");
            iconv(cd, (char**)&in, &src_len, (char**)&out, &dst_len);
            iconv_close(cd);
            char *r = malloc(256);
            strcpy(r, dst);
   
            return r;
}

char *GetChinese(char str[])  // 设置处理文字
{
            char* uni = NULL;
            char *count;
            char *code = malloc(strlen(str) * 4);
            code = GB2312_UTF8(str);
            int num;
            num = UTF8_UNICODE(code,&uni);
            count = malloc(num);
            if ( num != -1 ) {
                        sprintf(count,"%0X%0X",uni[1],uni[0]);
            } else {
                        return NULL;
            }
            free(uni);
            free(code);
            return count;
}

int scan_word(Draw_Font word)
{
        word->FT_error = 0;
        word->FT_error = FT_Init_FreeType(&(word->FT_Lib));  /* 初始化FreeType库 */
         
        if (word->FT_error) {
                word->FT_Lib = 0 ;
                perror("Init Lib");
                return -1;
        }   
        word->FT_error = FT_New_Face(word->FT_Lib, "./gs.ttf", 0 , &(word->FT_Face));
        if ( word->FT_error == FT_Err_Unknown_File_Format ) {  
                perror("FT_UNKNOWN_FILE_FORMAT");
                return -1;
        } else if (word->FT_error) {
                perror("FT_OPEN_FILE_ERROR");
                return -1;
        }
      
        FT_Set_Pixel_Sizes(word->FT_Face, 0, word->size);    /* 设定字体尺寸 */
        FT_Load_Glyph(word->FT_Face, FT_Get_Char_Index(word->FT_Face, strtol(GetChinese(word->word),NULL,16)), FT_LOAD_DEFAULT);
         
        word->FT_error = FT_Get_Glyph(word->FT_Face->glyph, &(word->FT_glyph));
         
        if ( !word->FT_error) {
                FT_Glyph_To_Bitmap(&(word->FT_glyph), FT_RENDER_MODE_NORMAL, 0 , 1);
                //FT_RENDER_MODE_NORMAL          这是默认渲染模式，它对应于8位抗锯齿位图。
                 
                word->FT_bitmap_glyph= (FT_BitmapGlyph)word->FT_glyph;
                 
                word->FT_bitmap = word->FT_bitmap_glyph->bitmap;
			}
        return 0;
}

int draw_word(Draw_Font word, int x, int y)
{
	int r, w;
	word->x = x;
	word->y = y;
	for (r = 0; r < word->FT_bitmap.rows; ++r) {
		for (w = 0; w < word->FT_bitmap.width; ++w) {
			if (word->FT_bitmap.buffer[r * word->FT_bitmap.width + w] != 0) {
				gs_fb_draw_pos(x + w, y + r, 255, 255, 255, 255);
				word->ex = x + w;
				word->ey = y + r;
			}
		}
	}
	return 0;
}

int destory_word(Draw_Font word)
{
	FT_Done_Glyph(word->FT_glyph);
	word->FT_glyph = NULL;
	FT_Done_Face(word->FT_Face);
	word->FT_Face = NULL;
	FT_Done_FreeType(word->FT_Lib);
	word->FT_Lib = NULL;   
	return 0;
}
