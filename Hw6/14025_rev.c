#include <stdio.h>

int arr[10][10] = {0};
int skip[10][10] = {0};
int n, ans=0;

int check(int a, int b) {
    int i;
    for (i=0; i<n; i++) {
        if (arr[a][i] || arr[i][b])
            return 0;
        else if ((a-i)>=0 && (b-i)>=0 && arr[a-i][b-i])
            return 0;
        else if ((a-i)>=0 && (b+i)<n && arr[a-i][b+i])
            return 0;
        else if ((a+i)<n && (b+i)<n && arr[a+i][b+i])
            return 0;
        else if ((a+i)<n && (b-i)>=0 && arr[a+i][b-i])
            return 0;
    }
    return 1;
}

void f(int a, int b) {
    if (a==n || b==n) return;
    if (check(a,b) && !skip[a][b]) {
        if (a == n-1) {
            ans++;
            return;
        }
        arr[a][b] = 1;
        f(a+1,0);
        arr[a][b] = 0;
    }
    f(a, b+1);
}

int main () {
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