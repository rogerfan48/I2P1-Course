// 14025 - Let the Queen cooks   

#include <stdio.h>

int arr[10][10] = {0};
int skip[10][10] = {0};
int n, ans=0;

int check(int x, int y) {
    int i;
    for (i=0; i<n; i++) {
        if (arr[x][i] || arr[i][y]) {
            return 0;
        } else if ((x-i)>=0 && (y-i)>=0 && arr[x-i][y-i]) {
            return 0;
        } else if ((x-i)>=0 && (y+i)<n && arr[x-i][y+i]) {
            return 0;
        } else if ((x+i)<n && (y-i)>=0 && arr[x+i][y-i]) {
            return 0;
        } else if ((x+i)<n && (y+i)<n && arr[x+i][y+i]) {
            return 0;
        }
    }
    return 1;
}

void f(int x, int y) {
    if (x==n || y==n) return;
    if (check(x, y) && !skip[x][y]) {
        if (x==n-1) {
            ans++;
        } else {
            arr[x][y] = 1;
            f(x+1,0);
            arr[x][y] = 0;
        }
    }
    f(x,y+1);
}

int main() {
    int i, j;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            scanf("%1d", &skip[i][j]);
        }
    }
    f(0,0);
    printf("%d\n", ans);
}