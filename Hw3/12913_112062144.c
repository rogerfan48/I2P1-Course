// 12913 - Big number addition

#include <stdio.h>

int main() {
    int A[101] = {0};
    int B[101] = {0};
    int C[101] = {0};
    int a=0, b=0, i, start=0;
    
    scanf("%d", &a);
    getc(stdin);
    for (i=a-1; i>=0; i--) {
        A[i] = getc(stdin) - 48;
    }
    getc(stdin);
    
    scanf("%d", &b);
    getc(stdin);
    for (i=b-1; i>=0; i--) {
        B[i] = getc(stdin) - 48;
    }
    getc(stdin);
    for (i=0; i<100; i++) {
        C[i] += A[i] + B[i];
        C[i+1] += C[i] / 10;
        C[i] %= 10;
        // printf("A[%d]=%d, B[%d]=%d, temp=%d, C[%d]=%d, C[%d]=%d\n", i, A[i], i, B[i], temp, i, C[i], i+1, C[i+1]);
    }
    for (i=100; i>=0; i--) {
        if (C[i]!=0 || start) {
            start = 1;
            printf("%d", C[i]);
        }
    }
    if (!start) printf("0");
}