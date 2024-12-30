// 12932 - Drop the ball

#include <stdio.h>

int arr[500][500] = {0};
int n, m;

int main() {
    int i, j;
    int x, y, start, times;
    
    scanf("%d %d", &n, &m);
    getc(stdin);                                // ! need flushing

    for(i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            switch (getc(stdin)) {
                case '/':
                    arr[i][j] = 0;
                case '\\':
                    arr[i][j] = 1;
            }
        }
        getc(stdin);
    }
    // for(i=0; i<n; i++) {
    //     for (j=0; j<m; j++) {
    //         printf("%d ", arr[i][j]);
    //     }
    //     printf("\n");
    // }

    scanf("%d", &times);

    for (i=0; i<times; i++) {
        scanf("%d", &start);
        x = 0;
        y = start-1;
        while (1) {
            if (arr[x][y]) {
                if (y==m-1) {
                    printf("Right!\n");
                    break;
                } else if (!arr[x][y+1]) {
                    printf("Stuck QQ\n");
                    break;
                } else if (x==n-1) {                    // ! the order is crucial, this should be put after above
                    printf("Position: %d\n", y+2);
                    break;
                } else {
                    x++;
                    y++;
                }
            } else {
                if (!y) {
                    printf("Left!\n");
                    break;
                } else if (arr[x][y-1]) {
                    printf("Stuck QQ\n");
                    break;
                } else if (x==n-1) {
                    printf("Position: %d\n", y);
                    break;
                } else {
                    x++;
                    y--;
                }
            }
        }
    }
}