// 13348 - DomoMaze - easy version 

#include <stdio.h>
#define int long long

int obs[20][20];
int arr[20][20];

signed main() {
    int h, w;
    scanf("%lld %lld", &h, &w);
    for (int i=0; i<h; i++)
        for (int j=0; j<w; j++) {
            scanf("%1lld", &obs[i][j]);
        }

    for (int i=0; i<h; i++)
        for (int j=0; j<w; j++) {
            if (obs[i][j]) arr[i][j]=0;
            else if (!i && !j) arr[i][j]=1;                // !
            else if (!i) arr[i][j] = arr[i][j-1];       // ! Don't initialize first row/col all to 1, since if any obs appears would make the following be 0 rather than 1.
            else if (!j) arr[i][j] = arr[i-1][j];       // !
            else arr[i][j] = arr[i-1][j-1] + arr[i][j-1] + arr[i-1][j];
        }

    printf("%lld\n", arr[h-1][w-1]);
}