#include <stdio.h>
#define EMPTY -1000

int q, r, q_now, r_now, ans, n;
int queen[10];
int rook[10];

int q_valid(int a, int b);
int r_valid(int a, int b);
void place(int level);

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        ans = 0;
        scanf("%d %d", &q, &r);
        q_now = 0; r_now = 0, n = q+r;
        for (int i=0; i<10; i++) {
            queen[i] = EMPTY;
            rook[i] = EMPTY;
        }
        place(0);
        printf("%d\n", ans);
    }
}

int q_valid(int a, int b) {
    for (int i=0; i<a; i++) {
        if (queen[i]==b || rook[i]==b || queen[i]==(b-a+i) || rook[i]==(b-a+i) || queen[i]==(a+b-i) || rook[i]==(a+b-i))
            return 0;
    }
    return 1;
}
int r_valid(int a, int b) {
    for (int i=0; i<a; i++) {
        if (queen[i]==b || rook[i]==b || queen[i]==(b-a+i) || queen[i]==(a+b-i))
            return 0;
    }
    return 1;
}

void place(int level) {
    if (level == n) {
        ans++;
        return;
    }
    for (int i=0; i<n; i++) {
        if (q_valid(level, i) && q_now<q) {
            queen[level] = i;
            q_now++;
            place(level+1);
            q_now--;
            queen[level] = EMPTY;
        }
        if (r_valid(level, i) && r_now<r) {
            rook[level] = i;
            r_now++;
            place(level+1);
            r_now--;
            rook[level] = EMPTY;
        }
    }
}