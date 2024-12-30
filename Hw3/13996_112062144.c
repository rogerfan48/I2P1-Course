// 13996 - Squidward Musical

#include <stdio.h>
#include <string.h>

int ans = 0;
char x[1001];

void f1(int n) {
    int delta = 1;
    while ((n-delta)>=0 && (n+delta)<strlen(x)) {
        if (x[n-delta] == x[n+delta]) {
            ans += 1;
            delta++;
        } else {
            return;
        }
    }
}

void f2(int n) {
    int delta = 0;
    while ((n-delta)>=0 && (n+1+delta)<strlen(x)) {
        if (x[n-delta] == x[n+1+delta]) {
            if (delta != 0)
                ans += 1;
            delta++;
        } else {
            return;
        }
    }
}

int main() {
    int i;
    scanf("%s", x);

    for (i=0; i<strlen(x); i++) {
        f1(i);
        f2(i);
    }
    printf("%d\n", ans);
}