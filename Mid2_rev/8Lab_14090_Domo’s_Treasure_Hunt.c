#include <stdio.h>
#include <limits.h>
#define int long long
#define MAX(a,b) (((a)>(b)) ? (a) : (b))

int h, w;
int arr[1024][1024];
int dp[1024][1024];         // ! cannot initialize them to 0

int f(int a, int b);

signed main() {
    scanf("%lld %lld", &w, &h);
    for (int i=0; i<h; i++) 
        for (int j=0; j<w; j++) {
            scanf("%lld", &arr[i][j]);
        }
    for (int i=0; i<h; i++)         // ! initialize them to -1
        for (int j=0; j<w; j++) {
            dp[i][j] = -1;
        }
    dp[0][0] = arr[0][0];
    f(h-1, w-1);
    printf("%lld\n", dp[h-1][w-1]);
}

int f(int a, int b) {
    if (dp[a][b]!=-1) return dp[a][b];
    if (a<0 || b<0) return LLONG_MIN;
    return dp[a][b] = (MAX(f(a-1,b),f(a,b-1)) + arr[a][b]);
}