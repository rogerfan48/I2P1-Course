#include <stdio.h>
#define int long long

int arr[20][20] = {0};
int obs[20][20];

signed main() {
    int h, w;
    scanf("%lld %lld", &h, &w);
    for (int i=0; i<h; i++)
        for (int j=0; j<w; j++) {
            scanf("%1lld", &obs[i][j]);
        }

    arr[0][0] = 1;
    for (int i=1; i<h; i++) {
        arr[i][0] = obs[i][0] ? 0 : arr[i-1][0];
    }
    for (int i=1; i<w; i++) {
        arr[0][i] = obs[0][i] ? 0 : arr[0][i-1];
    }
    for (int i=1; i<h; i++)
        for (int j=1; j<w; j++) {
            arr[i][j] = !obs[i][j] ? arr[i-1][j-1] + arr[i][j-1] + arr[i-1][j] : 0;
        }

    printf("%lld\n", arr[h-1][w-1]);
}