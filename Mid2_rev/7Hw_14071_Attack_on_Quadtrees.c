#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define MAX(a,b) (((a)>(b)) ? (a) : (b))

int h, w, num=0, l;
int arr[128][128] = {0};
int ans[10000][8] = {0};
int now[8] = {0};

void f(int level, int a, int b);

int main() {
    scanf("%d %d", &h, &w);
    for (int i=0; i<h; i++)
        for (int j=0; j<w; j++) {
            scanf("%d", &arr[i][j]);
        }

    l = ceil(log2(MAX(h,w)));
    f(0, 0, 0);
    printf("%d\n", num);
    for (int i=0; i<num; i++) {
        printf("1");
        for (int j=1; j<=ans[i][0]; j++) {
            printf("%d", ans[i][j]);
        }
        printf("\n");
    }
}

void f(int level, int a, int b) {
    int width = pow(2, l-level);
    int coh = 1;
    int std = arr[a][b];
    for (int i=0; i<width; i++) {
        for (int j=0; j<width; j++) {
            if (arr[a+i][b+j] != std) {         // ! be careful: [a+i][b+j]
                coh = 0;
                goto out;
            }
        }
    }
    out:
    if (coh) {
        if (std) {
            ans[num][0] = level;
            for (int i=1; i<=level; i++) {
                ans[num][i] = now[i];
            }
            num++;
        }
    } else {
        now[level+1] = 0;
        f(level+1, a, b);
        now[level+1] = 1;
        f(level+1, a, b+width/2);
        now[level+1] = 2;
        f(level+1, a+width/2, b);
        now[level+1] = 3;
        f(level+1, a+width/2, b+width/2);
    }
}