// 13647 - Reverse Fibonacci numbers

# include <stdio.h>

long arr[31] = {0};

int f(int x) {
    if (arr[x]) return arr[x];
    return f(x-2)-f(x-1);
}

int main() {
    long a, b, n;
    scanf("%ld %ld %ld", &a, &b, &n);
    arr[0] = a;
    arr[1] = b;
    printf("%d\n", f(n));
}