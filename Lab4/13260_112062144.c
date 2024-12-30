// 13260 - Nappa's Attack

#include <stdio.h>

int main() {
    int n, ans=0, i, j;
    scanf("%d", &n);

    for (i=1; i<=n; i++) {
        ans=0;
        for (j=0; j<n-i; j++) {
            printf(" ");
        }
        for (j=0; j<i; j++) {
            printf("%d", ++ans);
        }
        for (j=0; j<i-1; j++) {
            printf("%d", --ans);
        }
        printf("\n");
    }
}