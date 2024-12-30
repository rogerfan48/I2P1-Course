// 14042 - Capybara Hunts All!   

#include <stdio.h>
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

char maze[501][501];
int ans=0;

void f(int a, int b, int dist, int pos) {
    if (pos!=DOWN && maze[a-1][b] != '#') {
        if (maze[a-1][b] == 'M')
            ans += 2*dist;
        f(a-1, b, dist+1, UP);
    }
    if (pos!=LEFT && maze[a][b+1] != '#') {
        if (maze[a][b+1] == 'M')
            ans += 2*dist;
        f(a, b+1, dist+1, RIGHT);
    }
    if (pos!=UP && maze[a+1][b] != '#') {
        if (maze[a+1][b] == 'M')
            ans += 2*dist;
        f(a+1, b, dist+1, DOWN);
    }
    if (pos!=RIGHT && maze[a][b-1] != '#') {
        if (maze[a][b-1] == 'M')
            ans += 2*dist;
        f(a, b-1, dist+1, LEFT);
    }
}

int main() {
    int i, j;
    int w, h, a, b;
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