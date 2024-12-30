#include <stdio.h>
#include <string.h>
#define LIMIT 1001

int main() {
    char str[LIMIT];
    char title[LIMIT];
    char *now;
    int ans=0;

    while (fgets(str, LIMIT, stdin) != NULL) {          // ! fgets: whole line
        now = strtok(str, "<");
        while (now != NULL) {
            if (strncmp(now, "title", 5) == 0) {        // ! strncmp
                strcpy(title, now+6);
            } else if (strncmp(now, "a", 1) == 0) {
                ans++;
            }
            now = strtok(NULL, "<");                    // !
        }
    }
    printf("%s\n%d\n", title, ans);
}