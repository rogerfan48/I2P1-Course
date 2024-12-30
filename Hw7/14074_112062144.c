// 14074 - Report on Quadtrees

#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX(a,b) (((a)>(b)) ? (a) : (b))

int n_index;
int arr[128][128] = {0};
char path[8200][10] = {0};

void fill(int level, int a, int b) {
    int i, j, limit=pow(2,level);
    for (i=0; i<limit; i++) {
        for (j=0; j<limit; j++) {
            arr[a+i][b+j] = 1;
        }
    }
}

void f(char *path, int n, int a, int b) {
    if (path[n] == '\0') {
        fill(n_index-n+1, a, b);                // ! -n+1
        return;
    }
    int width = (int)pow(2, n_index-n);         // ! -n
    switch (path[n]) {
        case '0':
            f(path, n+1, a, b);
            break;
        case '1':
            f(path, n+1, a, b+width);
            break;
        case '2':
            f(path, n+1, a+width, b);
            break;
        case '3':
            f(path, n+1, a+width, b+width);
    }
}

int main() {
    int i, j;
    int h, w, n_;
    scanf("%d", &n_);
    for (i=0; i<n_; i++) {
        scanf("%s", path[i]);
    }
    scanf("%d %d", &h, &w);
    n_index = ceil(log2(MAX(h,w)));
    for (i=0; i<n_; i++) {
        f(path[i], 1, 0, 0);
    }
    for (i=0; i<h; i++) {
        printf("%1d", arr[i][0]);
        for (j=1; j<w; j++) {
            printf(" %1d", arr[i][j]);
        }
        if (i<h-1) {
            printf("\n");
        }
    }
}