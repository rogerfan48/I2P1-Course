#include <stdio.h>
#include <string.h>

void sol() {
    char *ORI[51];
    char ori[5001];
    char dec[5001];
    int idx=0, len, status;
    
    scanf("%s", ori);
    char *now = strtok(ori, "/");
    while (now != NULL) {
        ORI[idx] = now;
        idx++;
        now = strtok(NULL, "/");
    }
    len = idx;

    scanf("%s", dec);
    now = strtok(dec, "/");
    while (now != NULL) {
        status = 0;
        for (int i=0; i<len; i++) {
            if (!strcmp(now, ORI[i])) {
                status = 1;
                break;
            }
        }
        if (!status) {
            printf("not valid\n");
            return;
        }
        now = strtok(NULL, "/");
    }
    printf("valid\n");
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--)
        sol();
}