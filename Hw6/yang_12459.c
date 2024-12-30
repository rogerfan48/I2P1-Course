// 12459 - Sierpinski Carpet

#include <stdio.h>
#define int long long

int n, ans=0;

void f(int x, int times) {
    if (times>n) return;
    ans += x;
    f(x*8, times+1);
}

signed main() {
    scanf("%lld", &n);
    f(1, 1);
    printf("%lld\n", ans);
}