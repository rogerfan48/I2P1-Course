#include <stdio.h>
#include <string.h>

int main() {
    char str[1001];
    char title[1001];
    char *now;
    int ans=0;

    while (fgets(str, 1001, stdin) != NULL) {
        now = strtok(str, "<");
        while (now != NULL) {
            if (!strncmp(now, "title", 5)) {
                strcpy(title, now+6);
            } else if (!strncmp(now, "a", 1)) {
                ans++;
            }
            now = strtok(NULL, "<");
        }
    }
    printf("%s\n%d\n", title, ans);
}