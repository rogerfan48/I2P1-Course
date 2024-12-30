// 14134 - Strawhats' Bento Set

#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    char s[25];
    scanf("%s", s);
    int length = strlen(s);
    int step = pow(2, length);

    for (int i=1; i<step; i++) {
        for(int j=0; j<length; j++) {
            if ((i>>j) & 1)
                printf("%c",s[j]);
        }
        printf("\n");
    }
    return 0;
}





// #include <stdio.h>
// #include <stdlib.h>

// typedef struct Node_s Node;
// typedef struct Head_s Head;
// struct Node_s {
//     char x;
//     Node *next;
// };
// struct Head_s {
//     Head *next;
//     Node *nodes;
//     Node *now;
// };

// void print(Head);
// void copy(Head *bp, Head *hp);

// int main() {
//     Head *hp, *bp, *head, *bottom;
//     Node *np, *tnp;
//     char c = getchar();
//     head = bottom = calloc(1, sizeof(Head));
//     head->now =  head->nodes = calloc(1, sizeof(Node));
//     head->now->x = c;

//     while ((c = getchar()) != '\n') {
//         bp = bottom = calloc(1, sizeof(Head));
//         bp->now = bp->nodes = calloc(1, sizeof(Node));
//         bp->now->x = c;

//         hp = head;
//         while (hp != NULL) {
//             bp = bp->next = calloc(1, sizeof(Head));
//             copy(bp, hp);
//             bp->now = bp->now->next = calloc(1, sizeof(Node));
//             bp->now->x = c;
//             if (hp->next == NULL) break;
//             hp = hp->next;
//         }
//         hp->next = bottom;
//     }
//     hp = head;
//     while (hp != NULL) {
//         print(*hp);
//         hp = hp->next;
//     }
// }

// void print(Head head) {
//     Node *np;
//     np = head.nodes;
//     while (np != NULL) {
//         printf("%c", np->x);
//         np = np->next;
//     }
//     printf("\n");
// }

// void copy(Head *bp, Head *hp) {
//     Node *cp, *ps;
//     cp = hp->nodes;
//     ps = bp->nodes = calloc(1, sizeof(Node));
//     ps->x = cp->x;
//     cp = cp->next;
//     while (cp != NULL) {
//         ps = ps->next = calloc(1, sizeof(Node));
//         ps->x = cp->x;
//         cp = cp->next;
//     }
//     bp->now = ps;
// }