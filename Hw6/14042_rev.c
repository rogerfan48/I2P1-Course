#include <stdio.h>

char maze[501][501];
int h, w;
int ans = 0;

void f(int a, int b, int step, int pos) {
    if (pos!=2 && maze[a-1][b]!='#') {
        if (maze[a-1][b]=='M')
            ans+=2*step;
        f(a-1, b, step+1, 0);
    }
    if (pos!=3 && maze[a][b+1]!='#') {
        if (maze[a][b+1]=='M')
            ans+=2*step;
        f(a, b+1, step+1, 1);
    }
    if (pos!=0 && maze[a+1][b]!='#') {
        if (maze[a+1][b]=='M')
            ans+=2*step;
        f(a+1, b, step+1, 2);
    }
    if (pos!=1 && maze[a][b-1]!='#') {
        if (maze[a][b-1]=='M')
            ans+=2*step;
        f(a, b-1, step+1, 3);
    }
}

int main() {
    int i, j;
    int a, b;
    scanf("%d %d", &h, &w);
    for (i=0; i<h; i++) {
        for (j=0; j<w; j++) {
            scanf(" %c", &maze[i][j]);
            if (maze[i][j] == 'S') {
                a = i;
                b = j;
            }
        }
    }
    f(a, b, 1, -1);
    printf("%d\n", ans);
}