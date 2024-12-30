// 13975 - Frieren and her Rizz 2

#include <stdio.h>

int main(){
    int a,b,c,d,e,f;
    scanf("%1d%1d%1d%1d%1d%1d", &a, &b, &c, &d, &e, &f);
    char ch = b * 16 + c * 8 + d * 4 + e * 2 + f + 64;
	ch = 155 - ch;
	ch = ch + a * 32;
    printf("%c\n", ch);
}