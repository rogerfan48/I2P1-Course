// 13970 - Frieren and her Rizz

// *******
//
// #include <stdio.h>
//
// int main(){
//     int a,b,c,d,e,f;
//     scanf("%1d%1d%1d%1d%1d%1d", &a, &b, &c, &d, &e, &f);
//     char ch = a *32 + b * 16 + c * 8 + d * 4 + e * 2 + f + 64;
//     printf("%c\n", ch);
// }
//
// *******

#include <stdio.h>

int pow2(int);

int main() {
    int num, i;
    int x = 0;

    scanf("%d", &num);

    for (i=0; i<6; i++) {
        x += (num % 10) * pow2(i);
        num /= 10;
    }
    printf("%c\n", 64+x);
}

int pow2(int n) {
    int z = 1;
    int i;
    for (i=0; i<n; i++) {
        z *= 2;
    }
    return z;
}