#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX(x,y) (((x)>(y)) ? (x) : (y))

int arr[128][128] = {0};
int n_index;
char *now;

void f(int n, int a, int b) {
    int width = pow(2, n_index-n);
    if (n==strlen(now)) {
        for (int i=0; i<width; i++) {
            for (int j=0; j<width; j++) {
                arr[a+i][b+j] = 1;
            }
        }
        return;
    }
    switch (now[n]) {
        case '0': f(n+1, a, b); break;
        case '1': f(n+1, a, b+width/2); break;
        case '2': f(n+1, a+width/2, b); break;
        case '3': f(n+1, a+width/2, b+width/2); break;
    }
}

int main() {
    int str_num, h, w;
    scanf("%d", &str_num);
    char strs[str_num][10];
    for (int i=0; i<str_num; i++) {
        getc(stdin);getc(stdin);
        scanf("%s", strs[i]);
    }
    scanf("%d %d", &h, &w);
    n_index = ceil(log2(MAX(h,w)));
    for (int i=0; i<str_num; i++) {
        now = strs[i];
        f(0, 0, 0);
    }

    for (int i=0; i<h; i++) {
        printf("%d", arr[i][0]);
        for (int j=1; j<w; j++) {
            printf(" %d", arr[i][j]);
        }
        if (i<h-1) printf("\n");
    }
}