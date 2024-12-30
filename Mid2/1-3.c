#include <stdio.h>
#define EMPTY -1000

int k, r, k_now, r_now, ans, n;
int knight[10];
int rook[10];
int row[10];

int k_valid(int a, int b);
int r_valid(int a, int b);
void place(int level);

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        ans = 0;
        scanf("%d %d", &k, &r);
        k_now = 0; r_now = 0, n = k+r;
        for (int i=0; i<10; i++) {
            knight[i] = EMPTY;
            rook[i] = EMPTY;
            row[i] = 0;
        }
        place(0);
        printf("%d\n", ans);
    }
}

int k_valid(int a, int b) {
    if (a>=1 && b>=2 && (knight[a-1]==(b-2) || rook[a-1]==(b-2))) return 0;
    if (a>=2 && b>=1 && (knight[a-2]==(b-1) || rook[a-2]==(b-1))) return 0;
    if (a>=2 && b<=(n-2) && (knight[a-2]==(b+1) || rook[a-2]==(b+1))) return 0;
    if (a>=1 && b<=(n-3) && (knight[a-1]==(b+2) || rook[a-1]==(b+2))) return 0;
    return 1;
}
int r_valid(int a, int b) {
    if (a>=1 && b>=2 && (knight[a-1]==(b-2))) return 0;
    if (a>=2 && b>=1 && (knight[a-2]==(b-1))) return 0;
    if (a>=2 && b<=(n-2) && (knight[a-2]==(b+1))) return 0;
    if (a>=1 && b<=(n-3) && (knight[a-1]==(b+2))) return 0;
    return 1;
}

void place(int level) {
    if (level == n) {
        ans++;
        return;
    }
    for (int i=0; i<n; i++) {
        if (k_valid(level, i) && k_now<k && !row[i]) {
            knight[level] = i;
            k_now++;
            row[i]=1;
            place(level+1);
            row[i]=0;
            k_now--;
            knight[level] = EMPTY;
        }
        if (r_valid(level, i) && r_now<r && !row[i]) {
            rook[level] = i;
            r_now++;
            row[i]=1;
            place(level+1);
            row[i]=0;
            r_now--;
            rook[level] = EMPTY;
        }
    }
}