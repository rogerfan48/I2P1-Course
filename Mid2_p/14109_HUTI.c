// 14109 - HUTI
// HINT: https://hackmd.io/@1GZ2SzPXTti04Lt4md85JA/BJsY9Nw4p
// ! bit XOR application
// ! X^0 == X
// ! X^X == 0

#include <stdio.h>

int main() {
    long long t, x=0, tmp;
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld", &tmp);
        x ^= tmp;
    }
    printf("%lld\n", x);
}