// 13014 - Happy A to B

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int K, success;
char end[10] = {0};

void swap(char *ori, int *pos, int a, int b);
void sol(char *ori, int *pos, int k);

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        char* ori = calloc(10, sizeof(char));
        int* pos = calloc(2, sizeof(int));      // store the position of x
        success = 0;
        scanf("%d", &K);
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                scanf(" %c", &ori[i*3+j]);
                if (ori[i*3+j] == 'x') {
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
        
        sol(ori, pos, 0);

        printf(success ? "Yes\n" : "No\n");
    }
}

void swap(char *ori, int *pos, int a, int b) {
    char temp = ori[(pos[0]+a)*3+(pos[1]+b)];
    ori[(pos[0]+a)*3+(pos[1]+b)] = ori[pos[0]*3+pos[1]];
    ori[pos[0]*3+pos[1]] = temp;
    pos[0] += a;
    pos[1] += b;
}

void sol(char *ori, int *pos, int k) {
    if (success) return;
    if (k<=K) {                             // ! less than K times
        int coh = 1;
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                if (ori[i*3+j] != end[i*3+j]) coh = 0;
            }
        }
        if (coh) {
            success = coh;
            return;
        }
    }
    if (k==K) return;                       // ! need to stop iterating

    char *temp1 = calloc(10, sizeof(char)); strcpy(temp1, ori);
    int *pos1 = calloc(2, sizeof(int)); pos1[0]=pos[0]; pos1[1]=pos[1];
    char *temp2 = calloc(10, sizeof(char)); strcpy(temp2, ori);
    int *pos2 = calloc(2, sizeof(int)); pos2[0]=pos[0]; pos2[1]=pos[1];
    char *temp3 = calloc(10, sizeof(char)); strcpy(temp3, ori);
    int *pos3 = calloc(2, sizeof(int)); pos3[0]=pos[0]; pos3[1]=pos[1];
    char *temp4 = calloc(10, sizeof(char)); strcpy(temp4, ori);
    int *pos4 = calloc(2, sizeof(int)); pos4[0]=pos[0]; pos4[1]=pos[1];

    free(ori);
    free(pos);
    
    if (pos1[0]!=0) {
        swap(temp1, pos1, -1, 0);
        sol(temp1, pos1, k+1);
    }
    if (success) return;
    if (pos2[1]!=2) {
        swap(temp2, pos2, 0, 1);
        sol(temp2, pos2, k+1);
    }
    if (success) return;
    if (pos3[0]!=2) {
        swap(temp3, pos3, 1, 0);
        sol(temp3, pos3, k+1);
    }
    if (success) return;
    if (pos4[1]!=0) {
        swap(temp4, pos4, 0, -1);
        sol(temp4, pos4, k+1);
    }
}