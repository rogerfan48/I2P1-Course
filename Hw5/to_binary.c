#include <stdio.h>

void toBinary(int n) {
    int r;
    r = n%2;
    if (n>=2)
        toBinary(n/2);
    printf("%d", r);
}

int main() {
    toBinary(18);
}