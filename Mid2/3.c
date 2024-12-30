#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int K, success;
char end[10];

void swap(char *now, int *pos, int a, int b);
void f(char *now, int *pos, int k);

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        success = 0;
        char *now = calloc(10, sizeof(char));
        int *pos = calloc(2, sizeof(int));
        scanf("%d", &K);
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                scanf(" %c", &now[i*3+j]);
                if (now[i*3+j] == 'x') {
                    pos[0] = i;
                    pos[1] = j;
                }
            }
        }
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                scanf(" %c", &end[i*3+j]);
            }
        }
        f(now, pos, 0);
        printf((success) ? "Yes\n" : "No\n");
    }
}

void swap(char *now, int *pos, int a, int b) {
    char tmp = now[pos[0]*3+pos[1]];
    now[pos[0]*3+pos[1]] = now[(pos[0]+a)*3+(pos[1]+b)];
    now[(pos[0]+a)*3+(pos[1]+b)] = tmp;
    pos[0] += a;
    pos[1] += b;
}

void f(char *now, int *pos, int k) {
    if (success) return;
    if (k<=K) {
        int coh = 1;
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                if (now[i*3+j] != end[i*3+j]) coh = 0;
            }
        }
        if (coh) {
            success = 1;
            return;
        }
    }
    if (k==K) return;

    char *tmp1 = calloc(10, sizeof(char)); strcpy(tmp1, now);
    int *pos1 = calloc(2, sizeof(int)); pos1[0] = pos[0]; pos1[1] = pos[1];
    char *tmp2 = calloc(10, sizeof(char)); strcpy(tmp2, now);
    int *pos2 = calloc(2, sizeof(int)); pos2[0] = pos[0]; pos2[1] = pos[1];
    char *tmp3 = calloc(10, sizeof(char)); strcpy(tmp3, now);
    int *pos3 = calloc(2, sizeof(int)); pos3[0] = pos[0]; pos3[1] = pos[1];
    char *tmp4 = calloc(10, sizeof(char)); strcpy(tmp4, now);
    int *pos4 = calloc(2, sizeof(int)); pos4[0] = pos[0]; pos4[1] = pos[1];

    if (pos[0] != 0) {
        swap(tmp1, pos1, -1, 0);
        f(tmp1, pos1, k+1);
    }
    if (success) return;
    if (pos[1] != 2) {
        swap(tmp2, pos2, 0, 1);
        f(tmp2, pos2, k+1);
    }
    if (success) return;
    if (pos[0] != 2) {
        swap(tmp3, pos3, 1, 0);
        f(tmp3, pos3, k+1);
    }
    if (success) return;
    if (pos[1] != 0) {
        swap(tmp4, pos4, 0, -1);
        f(tmp4, pos4, k+1);
    }
}