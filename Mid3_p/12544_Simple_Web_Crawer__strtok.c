#include <stdio.h>
#include <string.h>

int main() {
    char str[1001];
    char title[1000];
    int num=0;
    char *now;
    while (fgets(str, 1000, stdin) != NULL) {
        now = strtok(str, "<");
        now = strtok(NULL, "<");
        while (now != NULL) {
            if (!strncmp(now, "title", 5)) {
                sscanf(now+6, "%[^<]", title);
            } else if (!strncmp(now, "a ", 2)) {
                num++;
            }
            now = strtok(NULL, "<");
        }
    }
    printf("%s\n%d\n", title, num);
}