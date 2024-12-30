// 14040 - GCD

#include <stdio.h>

int main() {
    int a, b, dif=1;
    scanf("%d %d", &a, &b);
    if (a==b) {
        printf("%d\n", a);
        return 0;
    }
    while (dif) {
        if (a > b) {
            dif = a % b;
            a = dif;
        } else {
            dif = b % a;
            b = dif;
        }
    }
    printf("%d\n", a+b);
}