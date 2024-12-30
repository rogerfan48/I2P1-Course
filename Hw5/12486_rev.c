// 12486 - Tower of Hanoi

#include <stdio.h>

void hanoi(int x, char a, char b, char c) {
    if (x==1) {
        printf("move disk %d from rod %c to rod %c\n", x, a, c);
        return;
    }
    hanoi(x-1, a, c, b);
    printf("move disk %d from rod %c to rod %c\n", x, a, c);
    hanoi(x-1, b, a, c);
}

int main() {
    int n;
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
}