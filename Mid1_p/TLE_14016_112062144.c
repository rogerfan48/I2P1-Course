// 14016 - OSHINOKODA   

#include <stdio.h>

int main() {
    int T, N, i, j, ans=0, x, y, x0, y0;
    scanf("%d %d", &T, &N);
    int arr[N][N];
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for (i=0; i<T; i++) {
        ans=0;
        scanf("%d %d", &x0, &y0);
        for (j=0; j<N; j++) {
            ans += arr[x0][j];
            ans += arr[j][y0];
        }
        ans -= arr[x0][y0];
        x=x0; y=y0;
        while (x-1>=0 && y-1>=0) {
            ans += arr[--x][--y];
            // printf("lu: %d %d\n", x, y);
        }
        x=x0; y=y0;
        while (x-1>=0 && y+1<N) {
            ans += arr[--x][++y];
            // printf("ru: %d %d\n", x, y);
        }
        x=x0; y=y0;
        while (x+1<N && y-1>=0) {
            ans += arr[++x][--y];
            // printf("ld: %d %d\n", x, y);
        }
        x=x0; y=y0;
        while (x+1<N && y+1<N) {
            ans += arr[++x][++y];
            // printf("rd: %d %d\n", x, y);
        }
        printf("%d\n", ans);
    }
}