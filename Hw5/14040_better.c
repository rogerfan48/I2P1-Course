// 14040 - GCD

#include <stdio.h>

int gcd(int x, int y) {
    if (y==0)           // ! can't replace x with y, since it's meant to cancel the possibility to "%0"
        return x;
    return gcd(y, x%y);
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", gcd(a, b));
}