#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char cmd[20];
    int len, idx, idx2;
    char c, *tmp;
    char **table = malloc(10*sizeof(char *));
    for (int i=0; i<10; i++) {
        table[i] = malloc(sizeof(char));
        table[i][0] = '\0';
    }

    while (scanf("%s", cmd) != EOF) {
        if (!strcmp(cmd, "print")) {
            for (int i=0; i<10; i++) {
                if (!strcmp(table[i], "")) {
                    printf("%d: No Contents\n", i);
                } else {
                    printf("%d: %s\n", i, table[i]);
                }
            }
        } else if (!strcmp(cmd, "all")) {
            scanf(" %c %d", &c, &len);
            for (int i=0; i<10; i++) {
                free(table[i]);
                table[i] = malloc((len+1)*sizeof(char));
                for (int j=0; j<len; j++) {
                    table[i][j] = c;
                }
                table[i][len] = '\0';
            }
        } else if (!strcmp(cmd, "place")) {
            scanf("%d", &idx);
            free(table[idx]);
            table[idx] = malloc(10002 * sizeof(char));
            scanf("%s", table[idx]);
        } else if (!strcmp(cmd, "swap")) {
            scanf("%d %d", &idx, &idx2);
            tmp = table[idx];
            table[idx] = table[idx2];
            table[idx2] = tmp;
        } else if (!strcmp(cmd, "clear")) {
            for (int i=0; i<10; i++) {
                free(table[i]);
                table[i] = malloc(sizeof(char));
                table[i][0] = '\0';
            }
        } else if (!strcmp(cmd, "exit")) {
            break;
        } else if (!strcmp(cmd, "shiftleft")) {
            tmp = table[0];
            for (int i=0; i<9; i++) {
                table[i] = table[i+1];
            }
            table[9] = tmp;
        } else if (!strcmp(cmd, "shiftright")) {
            tmp = table[9];
            for (int i=9; i>0; i--) {
                table[i] = table[i-1];
            }
            table[0] = tmp;
        }
    }
}