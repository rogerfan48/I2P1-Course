// 14072 - We count to 24

#include <stdio.h>

double data[4];
int order[24][4];
int occupied[4] = {0};
int temp[4];
int oper[64][3];
int n=0, n_=0;

void calcOrder(int);
void findNextNotUsed(int*); 
void calcOperOrder(int);
double calc(double, double, int);

int main() {
    int i, j, w;
    int numOfData;
    int pass=0;

    calcOrder(0);
    calcOperOrder(0);
    
    // for (i=0; i<24; i++) {
    //     for (j=0; j<4; j++) {
    //         printf("%d ", order[i][j]);
    //     }
    //     printf("\n");
    // }
    // for (i=0; i<64; i++) {
    //     for (j=0; j<3; j++) {
    //         printf("%d ", oper[i][j]);
    //     }
    //     printf("\n");
    // }

    scanf("%d", &numOfData);
    for (w=0; w<numOfData; w++) {
        pass=0;
        for (i=0; i<4; i++) {
            scanf("%lf", &data[i]);
        }

        for (i=0; i<24; i++) {
            for (j=0; j<64; j++) {
                if (
                calc(calc(calc(data[order[i][0]], data[order[i][1]], oper[j][0]), data[order[i][2]], oper[j][1]), data[order[i][3]], oper[j][2])==24 ||
                calc(calc(data[order[i][0]], calc(data[order[i][1]], data[order[i][2]], oper[j][1]), oper[j][0]), data[order[i][3]], oper[j][2])==24 ||
                calc(data[order[i][0]], calc(calc(data[order[i][1]], data[order[i][2]], oper[j][1]), data[order[i][3]], oper[j][2]), oper[j][0])==24 ||
                calc(calc(data[order[i][0]], data[order[i][1]], oper[j][0]), calc(data[order[i][2]], data[order[i][3]], oper[j][2]), oper[j][1])==24 ||
                calc(data[order[i][0]], calc(data[order[i][1]], calc(data[order[i][2]], data[order[i][3]], oper[j][2]), oper[j][1]), oper[j][0])==24
                ) {
                    pass = 1;
                    break;
                }
            }
            if (pass) {
                break;
            }
        }
        if (pass) {
            printf("Safe\n");
        } else {
            printf("Disqualified\n");
        }
    }
}

void calcOrder(int index) {
    int now=-1;
    int i;
    findNextNotUsed(&now);
    if (index==3) {
        temp[index] = now;
        for (i=0; i<4; i++) {
            order[n][i] = temp[i];
        }
        n++;
        return;
    }
    do {
        occupied[now] = 1;
        temp[index] = now;
        calcOrder(index+1);
        occupied[now] = 0;
        findNextNotUsed(&now);
    } while (now != -1);
}

void findNextNotUsed(int *now) {
    int i;
    for (i=(*now)+1; i<4; i++) {
        if (!occupied[i]) {
            *now = i;
            return;
        }
    }
    *now = -1;
}

void calcOperOrder(int index) {
    int i;
    if (index==3) {
        for (i=0; i<3; i++) {
            oper[n_][i] = temp[i];
        }
        n_++;
        return;
    }
    temp[index] = 0;
    do {
        calcOperOrder(index+1);
        temp[index]++;
    } while (temp[index]<4);
}

double calc(double a, double b, int op) {
    switch (op) {
        case 0:
            return a+b;
        case 1:
            return a-b;
        case 2:
            return a*b;
        case 3:
            if (b==0) return -99999999;
            return a/b;
        default:
            printf("error");
            return -1;
    }
}