#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

#define MAXLEN 68

const wchar_t eng[MAXLEN] = L"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ[]{};':\",.<>#`~";

const wchar_t rus[MAXLEN] = L"фисвуапршолдьтщзйкыегмцчняФИСВУАПРШОЛДЬТЩЗЙКЫЕГМЦЧНЯхъХЪжэЖЭбюБЮ№ёЁ";

int main(int argc, char *argv[])
{

    if (argc != 2)
        return 1;

    setlocale(LC_ALL, "");
    
    int j, i = 0;
    int len = mbstowcs(NULL, argv[1], 0);
    wchar_t src[len], res[len];
    
    mbstowcs(src, argv[1], len);

    while (src[i] == ' ')
        res[i++] = ' ';

    for ( ; i < len; i++) {
        res[i] = src[i];
        for (j = 0; j < MAXLEN; j++) {
            if (src[i] >= 1000 && src[i] == rus[j]) {
                res[i] = eng[j];
                break;
            } else if (src[i] == eng[j]) {
                res[i] = rus[j];
                break;
            }
        }
    }

    res[i] = '\0';
    wprintf(L"%ls", res);
        
    return 0;
}
