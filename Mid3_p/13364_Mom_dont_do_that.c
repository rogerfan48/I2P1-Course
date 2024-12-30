// 13364 - Mom, don't do that

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *ori[51];
    char dec[5001];
    int status[51] = {0};
    char *now;
    int t, num, valid, appear, cont, times;

    scanf("%d", &t);
    while (t--) {
        valid = 1; num=0;               // ? 初始化
        for (int i=0; i<51; i++) {      
            status[i] = 0;
        }

        scanf("%s", dec);               // ? 將 ori 分段儲存
        now = strtok(dec, "/");
        while (now != NULL) {
            ori[num] = malloc((strlen(now)+1)*sizeof(char));
            strcpy(ori[num], now);
            num++;
            now = strtok(NULL, "/");
        }

        scanf("%s", dec);               // ? 確保所有 dec 的片段皆有出現在 ori 中
        now = strtok(dec, "/");
        while (now != NULL) {
            appear = 0;
            for (int i=0; i<num; i++) {
                if (!strcmp(ori[i], now)) {
                    appear = 1;
                    status[i] = 1;
                }
            }
            if (!appear) {
                valid = 0;
                goto end;
            }
            now = strtok(NULL, "/");
        }

        // cont = 0; times = 0;            // ? 確保 dec 片段在 ori 中連續
        // for (int i=0; i<num; i++) {
        //     if (!cont && status[i]) {
        //         cont = 1;
        //         times++;
        //     } else if (cont && !status[i]) {
        //         cont = 0;
        //     }
        //     if (times > 1) {
        //         valid = 0;
        //         goto end;
        //     }
        // }

    end: printf((valid) ? "valid\n" : "not valid\n");
    }
}





// int main() {
//     char ori[5001];
//     char dec[5001];
//     char *now;
//     int t, valid;
//     scanf("%d", &t);
//     while (t--) {
//         valid = 1;
//         scanf("%s", ori);
//         scanf("%s", dec);
//         now = strtok(dec, "/");
//         while (now != NULL) {
//             if (strstr(ori, now) == NULL) {
//                 valid = 0;
//             }
//             now = strtok(NULL, "/");
//         }
//         printf((valid) ? "valid\n" : "not valid\n");
//     }
// }