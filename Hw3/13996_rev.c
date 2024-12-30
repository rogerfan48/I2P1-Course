#include <stdio.h>
#include <string.h>

int ans = 0, n;
char x[1001];

void f1(int a) {
    int delta = 1;
    while ((a-delta)>=0 && (a+delta)<n) {
        if (x[a-delta] == x[a+delta]) {
            ans++;
            delta++;
        } else return;
    }
}
void f2(int a) {
    int delta = 0;
    while ((a-delta)>=0 && (a+1+delta)<n) {
        if (x[a-delta] == x[a+1+delta]) {           // !!!!! a+"1"+delta
            if (delta != 0)                         // !!!!!
                ans++;
            delta++;
        } else return;
    }
}

int main() {
    int i;
    scanf("%s", x);

    n = strlen(x);
    for (i=0; i<n; i++) {                           // !!!!! run both f1() and f2()
        f1(i);
        f2(i);
    }
    printf("%d\n", ans);
}