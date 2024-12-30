// 14029 - Piece of a Dragon Curve

#include <stdio.h>
#include <math.h>
#define int long long

int rt(int x) {          // rotate times
    if (x==1) return 0;
    return rt((int)pow(2,ceil(log2(x)))-x+1) + 1;       // ! difficult
}

signed main() {
    int i, j;
    int n, s;
    int top=0, down=0, left=0, right=0, x=0, y=0;

    scanf("%lld %lld", &n, &s);
    int arr[n];
    for (i=0; i<n; i++) {
        arr[i] = rt(s+i)%4;
    }

    for (i=0; i<n; i++) {
        switch (arr[i]) {
            case 0:
                y++;
                top = y>top ? y : top;
                break;                          // ! don't forget the break;
            case 1:
                x++;
                right = x>right ? x : right;
                break;
            case 2:
                y--;
                down = y<down ? y : down;
                break;
            case 3:
                x--;
                left = x<left ? x : left;
        }
    }

    int h = 2*(top-down)+1;
    int w = 2*(right-left)+1;
    char graph[h][w];

    for (i=0; i<h; i++) {
        for (j=0; j<w; j++) {
            graph[i][j] = '.';
        }
    }
    
    int a = 2*top;
    int b = (-2)*left;
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