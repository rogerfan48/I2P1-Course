// 11635 - Position

#include <stdio.h>

int small[26][100000] = {0};
int big[26][100000] = {0};
int indexS[26] = {0}; 
int indexB[26] = {0};

int main() {
    int i, j, num=0;
    char chr;
    while (scanf(" %c", &chr)!=EOF) {
        if (chr>='a' && chr<='z') {
            small[chr-'a'][indexS[chr-'a']++] = num;
        } else {
            big[chr-'A'][indexB[chr-'A']++] = num;
        }
        num++;
    }
    for (i=0; i<26; i++) {
        if (indexB[i]) {
            printf("%c:", 'A'+i);
            for (j=0; j<indexB[i]; j++) {
                printf(" %d", big[i][j]);
            }
            printf("\n");
        }
    }
    for (i=0; i<26; i++) {
        if (indexS[i]) {
            printf("%c:", 'a'+i);
            for (j=0; j<indexS[i]; j++) {
                printf(" %d", small[i][j]);
            }
            printf("\n");
        }
    }
}