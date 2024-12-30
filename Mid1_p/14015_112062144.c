// 14015 - Hacker Domo

#include <stdio.h>

int main() {
    int N, R, i, j, now=1, end=0;
    int x[10][100000]={0};
    int index[10]={0};

    scanf("%d %d", &N, &R);
    while (1) {
        for (i=0; i<R-1; i++) {
            if (now>N) {
                end=1;
                break;
            }
            x[i][index[i]++] = now++;
        }
        for (i=R-1; i>0; i--) {
            if (now>N) {
                end=1;
                break;
            }
            x[i][index[i]++] = now++;
        }
        if (end) break;
    }
    printf("1");
    for (j=1; j<index[0]; j++) {
        printf(" %d", x[0][j]);
    }
    for (i=1; i<R; i++) {
        for (j=0; j<index[i]; j++) {
            printf(" %d", x[i][j]);
        }
    }
    printf("\n");
}