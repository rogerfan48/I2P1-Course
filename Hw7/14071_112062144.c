// 14071 - Attack on Quadtrees

#include <stdio.h>
#include <math.h>
#define MAX(A,B) (((A)>(B)) ? (A) : (B))

int arr[128][128] = {0};
int ans_num=0;
int ans[10000][10] = {0};
int n_index;
int path[10] = {0};

void f(int path_len, int a, int b) {
    int i, j;
    int width = (int)pow(2, n_index-path_len);
    int need_break = 0;
    int flag = arr[a][b];
    for (i=0; i<width; i++) {
        for (j=0; j<width; j++) {
            if (arr[a+i][b+j] != flag)
                need_break = 1;
        }
    }
    if (!need_break) {
        if (flag) {
            ans[ans_num][0] = path_len;
            for (i=1; i<=path_len; i++) {                   // ! <=
                ans[ans_num][i] = path[i];
            }
            ans_num++;
        }
    } else {
        path[path_len+1] = 0;
        f(path_len+1, a, b);
        path[path_len+1] = 1;
        f(path_len+1, a, b+width/2);
        path[path_len+1] = 2;
        f(path_len+1, a+width/2, b);
        path[path_len+1] = 3;
        f(path_len+1, a+width/2, b+width/2);
    }
}

int main() {
    int i, j;
    int h, w;
    scanf("%d %d", &h, &w);
    for (i=0; i<h; i++) {
        for (j=0; j<w; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }
    n_index = ceil(log2(MAX(h,w)));

    int path_len = 0;
    f(path_len, 0, 0);
    printf("%d\n", ans_num);
    for (i=0; i<ans_num; i++) {
        printf("1");
        for (j=1; j<=ans[i][0]; j++) {                      // ! <=
            printf("%d", ans[i][j]);
        }
        printf("\n");
    }
}