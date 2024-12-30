// 13648 - Text maze

#include <stdio.h>

int n, fs=1;
char map[100][100];
char target[3] = {0};
char left[8] = {'a', 'f', 'k', 'p', 'E', 'J', 'O', 'T'};
char right[8] = {'b', 'g', 'l', 'q', 'D', 'I', 'N', 'S'};
char up[8] = {'c', 'h', 'm', 'r', 'C', 'H', 'M', 'R'};
char down[8] = {'d', 'i', 'n', 's', 'B', 'G', 'L', 'Q'};
char spe[8] = {'e', 'j', 'o', 't', 'A', 'F', 'K', 'P'};
int order[8][2] = {{-1,-1},{0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1}};

int inRange(int, int);
void findB(int, int);
void findS(int, int);
char isInArr(char, char*);

int main() {
    int i, j;
    int S, x, y;

    scanf("%d %d %d %d", &n, &S, &x, &y);
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            scanf(" %c", &map[j][i]);
        }
    }

    char ans[S+1];
    ans[S] = '\0';

    i=x;x=y;y=i;

    printf("%c", map[x][y]);
    for (i=0; i<S; i++) {
        fs ? findS(x, y) : findB(x, y);
        if (isInArr(target[0], left)) {
            x--;
        } else if (isInArr(target[0], right)) {
            x++;
        } else if (isInArr(target[0], up)) {
            y--;
        } else if (isInArr(target[0], down)) {
            y++;
        } else {
            x = target[1];
            y = target[2];
            if (isInArr(target[0], spe))
                fs = fs ? 0 : 1;
        }
        if (!inRange(x, y)) {
            ans[i]='\0';
            break;
        }
        ans[i] = map[x][y];
    }
    printf("%s", ans);
}

int inRange(int x, int y) {
    return (x>=0 && y>=0 && x<n && y<n) ? 1 : 0;
}

void findB(int x, int y) {
    int i;
    target[0] = 0;
    for (i=0; i<8; i++) {
        if (inRange(x+order[i][0], y+order[i][1]) && (!target[0] || map[x+order[i][0]][y+order[i][1]] >= target[0])) {
            target[0] = map[x+order[i][0]][y+order[i][1]];
            target[1] = x+order[i][0];
            target[2] = y+order[i][1];
        }
    }
}
void findS(int x, int y) {
    int i;
    target[0] = 0;
    for (i=0; i<8; i++) {
        if (inRange(x+order[i][0], y+order[i][1]) && (!target[0] || map[x+order[i][0]][y+order[i][1]] <= target[0])) {
            target[0] = map[x+order[i][0]][y+order[i][1]];
            target[1] = x+order[i][0];
            target[2] = y+order[i][1];
        }
    }
}

char isInArr(char elem, char * arr) {
    int i;
    for (i=0; i<8; i++) {
        if (elem == arr[i])
            return elem;
    }
    return 0;
}

// F k C W Y V h H M X
// e r x R i j u m d Q
// s n t v p D S E g I
// q f w G A N l o z L
// P T J K B b y O U a
// r F h i J t P m M j
// C G f H Y Q c I L K
// N z T g E D R n b a
// w V x q B U y O s v
// l d W S u o X A p k