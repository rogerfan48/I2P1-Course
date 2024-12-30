#include <stdio.h>
#include <math.h>
#define MAX(x,y) (((x)>(y)) ? (x) : (y))

int arr[128][128] = {0};
int n_index;
int now[10];
int ans_num = 0;
int ans[10000][10];

void f(int n, int a, int b) {
    int width = pow(2, n_index-n);
    int sample = arr[a][b];
    int same = 1;
    for (int i=0; i<width; i++) {
        for (int j=0; j<width; j++) {
            if (arr[a+i][b+j] != sample) same = 0;
        }
    }
    if (same) {
        if (sample) {
            ans[ans_num][0] = n;
            for (int i=1; i<=n; i++) {
                ans[ans_num][i] = now[i];
            }
            ans_num++;
        }
    } else {
        now[n+1] = 0;
        f(n+1, a, b);
        now[n+1] = 1;
        f(n+1, a, b+width/2);
        now[n+1] = 2;
        f(n+1, a+width/2, b);
        now[n+1] = 3;
        f(n+1, a+width/2, b+width/2);
    }
}

int main() {
    int h, w;
    scanf("%d %d", &h, &w);
    n_index = ceil(log2(MAX(h,w)));
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    
    f(0, 0, 0);
    printf("%d\n", ans_num);
    for (int i=0; i<ans_num; i++) {
        printf("1"); 
        for (int j=1; j<=ans[i][0]; j++) {
            printf("%d", ans[i][j]);
        }
        printf("\n");
    }
}