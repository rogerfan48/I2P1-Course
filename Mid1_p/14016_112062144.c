// 14016 - OSHINOKODA

#include <stdio.h>

int main() {
    int T, N, i, j, x, y;
    scanf("%d %d", &T, &N);
    
    int arr[1200][1200] = {0};
    int row[1200] = {0};
    int column[1200] = {0};
    int diaF[2400] = {0};
    int diaB[2400] = {0};

    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            row[i] += arr[i][j];
            column[j] += arr[i][j];
            diaF[i+j] += arr[i][j];
            diaB[N+j-i] += arr[i][j];
        }
    }
    
    // ? Inspect "row, column, diaF, diaB" contents
    // for (i=0; i<N; i++) {
    //     printf("row[%d] = %d\n", i, row[i]);
    // }
    // for (i=0; i<N; i++) {
    //     printf("column[%d] = %d\n", i, column[i]);
    // }
    // for (i=0; i<2*N-1; i++) {
    //     printf("diaF[%d] = %d\n", i, diaF[i]);
    // }
    // for (i=0; i<2*N-1; i++) {
    //     printf("diaB[%d] = %d\n", i, diaB[i]);
    // }

    for (i=0; i<T; i++) {
        scanf("%d %d", &x, &y);
        printf("%d\n", row[x]+column[y]+diaF[x+y]+diaB[N+y-x]-arr[x][y]*3);
    }
}

// ? Finding the rules of diaF and diaB
// 00 01 02 03 04
// 10 11 12 13 14
// 20 21 22 23 24
// 30 31 32 33 34
// 40 41 42 43 44