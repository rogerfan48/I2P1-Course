#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    char str[22];
    scanf("%s", str);
    int len = strlen(str);
    int steps = (int)pow(2, len);

    for (int i=1; i<steps; i++) {
        for (int j=0; j<len; j++) {
            if ((i>>j) & 1)
                printf("%c", str[j]);
        }
        printf("\n");
    }
}