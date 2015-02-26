#include <stdio.h>
#include <string.h>

int cover(char c1);
int get_color(char c1, char c2);

void gs_get_color(char *pcolor, unsigned char *r, unsigned char *g, unsigned char *b)
{
    *r = get_color(*pcolor, *(pcolor+1)); 
    *g = get_color(*(pcolor+2), *(pcolor+3)); 
    *b = get_color(*(pcolor+4), *(pcolor+5)); 
}

int get_color(char c1, char c2)
{
    return (cover(c1) * 16 + cover(c2));
}

int cover(char c1)
{
    int t = 0;
    if (c1 >= 'A' && c1 <= 'F') 
        t = c1 - 'A' + 10;
    else if(c1 >= 'a' && c1 <= 'f')
        t = c1 - 'a' + 10;
    else
        t = c1 - '0';
    return t;
}

//对"***x***"的字符串进行读取前后两个分量大小
void gs_get_size(char *size, int *op1, int *op2)
{
    int n = strlen(size);
    int count = 0;
    *op1 = 0;
    *op2 = 0;
    while(*size!='x'&&*size!='X') {
        *op1 = *op1 * 10 + *size - '0';
        size++;
        count++;
    }
    count++;
    size++;
    while (count < n) {
        *op2 = *op2 * 10 + *size - '0';
        size++;
        count++;
    }
}
