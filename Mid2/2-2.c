#include <stdio.h>
#define int long long
#define MIN(a,b) (((a)<(b)) ? (a) : (b))

int cost[110];
int dp[110];

int f(int a);

int main() {
    int t, c;
    scanf("%lld %lld", &t, &c);
    for (int i=0; i<c; i++) {
        scanf("%lld", &cost[i]);
    }
    if (c==1) {
        while (t--) {
            int now;
            scanf("%lld", &now);
            if (now==1) printf("%d\n", cost[0]);
            else printf("0\n");
        }
        return 0;
    }
    dp[0] = cost[0];
    dp[1] = cost[1];
    f(c+1);
    while (t--) {
        int now;
        scanf("%lld", &now);
        if (now==0) {
            printf("0\n");
            continue;
        } else if (now==1) {
            printf("%d\n", cost[0]);
        } else {
            printf("%lld\n", MIN(dp[now-2],dp[now-1]));
        }
    }
}

int f(int a) {
    if (dp[a]) return dp[a];
    return dp[a] = MIN(f(a-1),f(a-2)) + cost[a];
}