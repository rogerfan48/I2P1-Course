// 12544 - Simple Web Crawer

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[1001];                                     // 用來存每一行
    char *temp = malloc(20 * sizeof(char));             // 用來存每次 '<' 之後的字串，僅用於判斷是什麼tag
    char title[1000];
    int num=0;
    while (fgets(str, 1000, stdin) != NULL) {
        char *now = str;
        while ((now = strchr(now, '<')) != NULL) {
            now++;
            sscanf(now, "%[^> ]", temp);
            // printf("now = %s", now);
            // printf("temp = %s\n", temp);
            if (!strcmp(temp, "title")) {
                sscanf(now+6, "%[^<]", title);
            } else if (!strcmp(temp, "a")) {
                num++;
            }
            now++;
        }
    }
    printf("%s\n%d\n", title, num);
}