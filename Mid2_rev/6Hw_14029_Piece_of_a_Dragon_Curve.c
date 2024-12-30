#include <stdio.h>
#include <math.h>
#define int long long

int f(int x) {
    if (x==1) return 0;
    return f((int)pow(2,ceil(log2(x)))-x+1) + 1;
}

signed main() {
    int i, j;
    int n, s;

    scanf("%lld %lld", &n, &s);
    int arr[n];
    for (i=0; i<n; i++) {
        arr[i] = f(s+i)%4;
    }
    
    int up=0, down=0, right=0, left=0, a=0, b=0;
    for (i=0; i<n; i++) {
        switch (arr[i]) {
            case 0:
                a--;
                up = a<up ? a : up;
                break;
            case 1:
                b++;
                right = b>right ? b : right;
                break;
            case 2:
                a++;
                down = a>down ? a : down;
                break;
            case 3:
                b--;
                left = b<left ? b : left;
        }
    }

    int h = 2*(down-up)+1;
    int w = 2*(right-left)+1;
    char graph[h][w];

    for (i=0; i<h; i++) {
        for (j=0; j<w; j++) {
            graph[i][j] = '.';
        }
    }

    a = (-2)*up;
    b = (-2)*left;
    graph[a][b] = '#';
    for (i=0; i<n; i++) {
        switch (arr[i]) {
            case 0:
                graph[--a][b] = '#';
                graph[--a][b] = '#';
                break;
            case 1:
                graph[a][++b] = '#';
                graph[a][++b] = '#';
                break;
            case 2:
                graph[++a][b] = '#';
                graph[++a][b] = '#';
                break;
            case 3:
                graph[a][--b] = '#';
                graph[a][--b] = '#';
        }
    }

    for (i=0; i<h; i++) {
        for (j=0; j<w; j++) {
            printf("%c", graph[i][j]);
        }
        printf("\n");
    }
}