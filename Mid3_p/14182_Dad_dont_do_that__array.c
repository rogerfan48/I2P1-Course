// 14182 - Dad, don't do that

#include <stdio.h>

char x[1000005];
int K, len;
int k, pos=0;

int getSIdx();

int main() {
    char c;
    int sIdx, begin=0;
    while ((c = getchar()) != '\n') {
        x[pos++] = c;
    }
    x[pos] = '\0';
    len = pos;
    scanf("%d", &K);

    k=K; pos=0;
    while (k != 0 && (pos+k)<=len) {        // !!!
        sIdx = getSIdx();
        if (sIdx == pos) {                  // !!!
            pos++;
            continue;
        } else {
            for (int i=pos; i<sIdx; i++) {
                x[i] = 'n';
            }
            k -= (sIdx - pos);
            pos = sIdx + 1;                 // !!!
        }
    }
    while (k != 0) {
        for (int i=len-1; i>=len-k; i--) {
            x[i] = 'n';
        }
    }
    for (int i=0; i<len; i++) {
        // printf("%c", x[i]);
        if ((x[i] == '0' && !begin) || x[i] == 'n') continue;
        begin = 1;
        printf("%c", x[i]);
    }
    if (!begin) printf("0");
    printf("\n");
}

int getSIdx() {
    int t = k+1;
    int idx = pos;
    int smallestIdx;
    char c=127;
    // printf("initial: t=%d, idx=%d, x[idx]=%c, smallestIdx=%d\n", t, idx, x[idx], smallestIdx);
    while (t--) {
        if (x[idx] < c) {
            c = x[idx];
            smallestIdx = idx;
        }
        // printf("t=%d, idx=%d, x[idx]=%c, smallestIdx=%d\n", t, idx, x[idx], smallestIdx);
        idx++;
    }
    return smallestIdx;
}