// 14010 - Jangan Makan Indomieku   

#include <stdio.h>

int main() {
    long long n, k, i, j, ans;
    scanf("%lld %lld", &n, &k);

    printf("1\n");
    for (i=1; i<n; i++) {
        ans = 1;
        printf("1 ");
        if (i%2) {
            for (j=0; j<i; j++) {
                printf("%lld ", ans+=k);
            }
            for (j=0; j<i-1; j++) {
                printf("%lld ", ans-=k);
            }
        } else {
            for (j=0; j<i; j++) {
                printf("%lld ", ans*=k);
            }
            for (j=0; j<i-1; j++) {
                printf("%lld ", ans/=k);
            }
        }
        printf("1\n");
    }
}