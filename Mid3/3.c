#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char str[10005];
char title[10005];
int order[210];     // h=0; p=1
int pnum=0, hnum=0, num=0;

char **htable;
char **ptable;

int main() {
    char *now;
    char cmd[50];
    int len, idx, idx2;
    char c, *tmp;

    while (fgets(str, 10005, stdin) != NULL) {
        now = strtok(str, "<");
        while (now != NULL) {
            if (!strncmp(now, "title", 5)) {
                strcpy(title, now+6);
            } else if (!strncmp(now, "h1>", 3)) {
                hnum++;
                order[num++] = 0;
            } else if (!strncmp(now, "p>", 2)) {
                pnum++;
                order[num++] = 1;
            } else if (!strncmp(now, "/html>", 6)) {
                goto out;
            }
            now = strtok(NULL, "<");
        }
    }

    out:
    htable = malloc(hnum*sizeof(char*));
    ptable = malloc(pnum*sizeof(char*));
    for (int i=0; i<hnum; i++) {
        htable[i] = malloc(sizeof(char));
        htable[i][0] = '\0';
    }
    for (int i=0; i<pnum; i++) {
        ptable[i] = malloc(sizeof(char));
        ptable[i][0] = '\0';
    }

    int pidx, hidx;
    while (scanf("%s", cmd) != EOF) {
        if (!strcmp(cmd, "print")) {
            printf("<html>\n   <head>\n      <title>%s</title>\n   </head>\n   <body>\n", title);
            pidx=0; hidx=0;
            for (int i=0; i<num; i++) {
                if (order[i]) {
                    if (!strcmp(ptable[pidx], "")) {
                        printf("      <p>No Contents</p>\n");
                    } else {
                        printf("      <p>%s</p>\n", ptable[pidx]);
                    }
                    pidx++;
                } else {
                    if (!strcmp(htable[hidx], "")) {
                        printf("      <h1>No Contents</h1>\n");
                    } else {
                        printf("      <h1>%s</h1>\n", htable[hidx]);
                    }
                    hidx++;
                }
            }
            printf("   </body>\n</html>\n");
        } else if (!strcmp(cmd, "allP")) {
            scanf(" %c %d", &c, &len);
            for (int i=0; i<pnum; i++) {
                free(ptable[i]);
                ptable[i] = malloc((len+1)*sizeof(char));
                for (int j=0; j<len; j++) {
                    ptable[i][j] = c;
                }
                ptable[i][len] = '\0';
            }
        } else if (!strcmp(cmd, "allH1")) {
            scanf(" %c %d", &c, &len);
            for (int i=0; i<hnum; i++) {
                free(htable[i]);
                htable[i] = malloc((len+1)*sizeof(char));
                for (int j=0; j<len; j++) {
                    htable[i][j] = c;
                }
                htable[i][len] = '\0';
            }
        } 
         else if (!strcmp(cmd, "placeH1")) {
            scanf("%d", &idx);
            free(htable[idx]);
            htable[idx] = malloc(10005 * sizeof(char));
            scanf("%s", htable[idx]);
        }  else if (!strcmp(cmd, "placeP")) {
            scanf("%d", &idx);
            free(ptable[idx]);
            ptable[idx] = malloc(10005 * sizeof(char));
            scanf("%s", ptable[idx]);
        } 
        else if (!strcmp(cmd, "swapP")) {
            scanf("%d %d", &idx, &idx2);
            tmp = ptable[idx];
            ptable[idx] = ptable[idx2];
            ptable[idx2] = tmp;
        } else if (!strcmp(cmd, "swapH1")) {
            scanf("%d %d", &idx, &idx2);
            tmp = htable[idx];
            htable[idx] = htable[idx2];
            htable[idx2] = tmp;
        } 
        else if (!strcmp(cmd, "clear")) {
            for (int i=0; i<pnum; i++) {
                free(ptable[i]);
                ptable[i] = malloc(sizeof(char));
                ptable[i][0] = '\0';
            }
            for (int i=0; i<hnum; i++) {
                free(htable[i]);
                htable[i] = malloc(sizeof(char));
                htable[i][0] = '\0';
            }
        }
        else if (!strcmp(cmd, "exit")) {
            break;
        } else if (!strcmp(cmd, "shiftleftP")) {
            tmp = ptable[0];
            for (int i=0; i<(pnum-1); i++) {
                ptable[i] = ptable[i+1];
            }
            ptable[pnum-1] = tmp;
        } else if (!strcmp(cmd, "shiftleftH1")) {
            tmp = htable[0];
            for (int i=0; i<(hnum-1); i++) {
                htable[i] = htable[i+1];
            }
            htable[hnum-1] = tmp;
        } 
        else if (!strcmp(cmd, "shiftrightP")) {
            tmp = ptable[pnum-1];
            for (int i=(pnum-1); i>0; i--) {
                ptable[i] = ptable[i-1];
            }
            ptable[0] = tmp;
        } else if (!strcmp(cmd, "shiftrightH1")) {
            tmp = htable[hnum-1];
            for (int i=(hnum-1); i>0; i--) {
                htable[i] = htable[i-1];
            }
            htable[0] = tmp;
        } else if (!strcmp(cmd, "Newtitle")) {
            getchar();
            scanf("%[^\n]", title);
        }
    }
}