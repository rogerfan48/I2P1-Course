#include <stdio.h>

int main() {
    int m, n, i, start=0;
    int a[100] = {0};
    int b[100] = {0};
    int c[101] = {0};

    scanf("%d", &m);
    getc(stdin);
    for (i=m-1; i>=0; i--) {
        a[i] = getc(stdin) - '0';
    }
    getc(stdin);

    scanf("%d", &n);
    getc(stdin);
    for (i=n-1; i>=0; i--) {
        b[i] = getc(stdin) - '0';
    }
    getc(stdin);

    for (i=0; i<100; i++) {
        c[i] += a[i] + b[i];
        c[i+1] += c[i]/10;
        c[i] %= 10;
    }

    for (i=100; i>=0; i--) {
        if (c[i]!=0 || start) {
            start = 1;
            printf("%1d", c[i]);
        }
    }
    if (!start)
        printf("0");
}