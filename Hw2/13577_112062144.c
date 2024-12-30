// 13577 - Anya loves to encrypt

#include <stdio.h>

int main() {
    char str[6];
    int i;

    for (i=0; i<5; i++)
        scanf("%c", &str[i]);

    for (i=0; i<5; i++) {
        str[i] = str[i] + ('A'-'a');
        str[i] = ('A' + 'Z') - str[i];
        printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}