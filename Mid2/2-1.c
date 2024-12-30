#include <stdio.h>

int dp[50];

int f(int a);

int main() {
    int t;
    dp[0]=1;
    dp[1]=1;
    scanf("%d", &t);
    while (t--) {
        int now, ans;
        scanf("%d", &now);
        printf("%d\n", f(now));
    }
}

int f(int a) {
    if (dp[a]) return dp[a];
    return dp[a] = f(a-1) + f(a-2);
}