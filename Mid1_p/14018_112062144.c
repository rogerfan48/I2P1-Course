// 14018 - Another Hacker Domo

#include <stdio.h>
#define BREAK printf("Domo cannot crack this computer\n");error=1;break

char str[1001];
char ans[1000001];

int numLong(int x) {
    int l=0;
    while (x) {
        l++;
        x/=10;
    }
    return l;
}

int main() {
    int index, num, indexAns, i, error;
    char chr;
    while (scanf("%s", str)!=EOF) {
        index = 0; indexAns = 0; error = 0;
        
        while (1) {
            if (str[index]=='\0') {
                break;
            } else if (str[index]>='0' && str[index]<='9') {
                sscanf(&str[index], "%d", &num);
            } else {
                BREAK;
            }
            index += numLong(num);

            if (str[index]=='\0') {
                BREAK;
            } else if (str[index]=='\'') {
                if (str[index+2]!='\'' || !(str[index+1]>='0' && str[index+1]<='9')) {
                    BREAK;
                } else {
                    chr = str[index+1];
                    index+=3;
                }
            } else {
                chr = str[index++];
            }
            for (i=0; i<num; i++, indexAns++) {
                ans[indexAns] = chr;
            }
        }
        if (!error) {
            ans[indexAns] = '\0';
            printf("%s\n", ans);
        }
    }
}

// void next() {
//     printf("Domo cannot crack this computer\n");
//     while (1) {
//         char temp;
//         scanf("%c", &temp);
//         if (temp == '\n') return;
//     }
// }

// int main() {
//     int num, i;
//     char chr, temp;
//     while (1) {
//         if (!scanf("%d", &num)) {
//             scanf("%c", &temp);
//             if (temp == '\n') {
//                 printf("\n");
//                 continue;
//             }
//             next();
//             continue;
//         }
//         scanf("%c", &chr);
//         if (chr == '\n') {
//             next();
//             continue;
//         } else if (chr == '\'') {
//             scanf("%c", &chr);
//             if (chr>'9' || chr<'0') {
//                 next();
//                 continue;
//             }
//             scanf("%c", &temp);
//             if (temp != '\'') {
//                 next();
//                 continue;
//             }
//         }
//         for (i=0; i<num; i++) {
//             printf("%c", chr);
//         }
//     }
// }