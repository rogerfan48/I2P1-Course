// 14007 - The Girl I Like Forgot Her Glasses

#include <stdio.h>

int main() {
    int w, h, i, j;
    scanf("%d %d", &w, &h);

    float con[3][3];
    int arr[h][w];

    for (i=0; i<3; i++) {
        scanf("%f %f %f", &con[i][0], &con[i][1], &con[i][2]);
    }
    for (i=0; i<h; i++) {
        for (j=0; j<w; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for (i=1; i<h-1; i++) {
        for (j=1; j<w-1; j++) {
            printf("%4d ", (int)(arr[i-1][j-1]*con[0][0]+arr[i-1][j]*con[0][1]+arr[i-1][j+1]*con[0][2]+
                                 arr[i][j-1]*con[1][0]  +arr[i][j]*con[1][1]  +arr[i][j+1]*con[1][2]+
                                 arr[i+1][j-1]*con[2][0]+arr[i+1][j]*con[2][1]+arr[i+1][j+1]*con[2][2]));
        }
        printf("\n");
    }
}