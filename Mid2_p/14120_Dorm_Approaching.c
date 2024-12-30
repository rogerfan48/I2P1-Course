// 14120 - A Dorm is Approaching
// see my notes: consider NODE and use AB theorem

#include <stdio.h>
#define int long long
#define MOD (int)(1e9+7)

int A, B, n;

void f(int now) {
    if (!now) return;
    int tmp = A;
    A = (A*4+B) % MOD;
    B = (tmp+B*2) % MOD;
    f(now-1);
}

signed main() {
    int t;
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld", &n);
        A = 5; B = 3;
        if (n==1) {
            printf("2\n");
            continue;
        }
        f(n-2);
        printf("%lld\n", (A+B) % MOD);
    }
}