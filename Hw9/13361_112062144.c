// 13361 - Cardcaptor Sakura

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_Node Node;
struct s_Node{
    int x;
    Node *next;
};

void clear(Node*);

int main() {
    Node head[10];
    Node *np;
    char s[10];
    int idx, idx2, num, len;

    for (int i=0; i<10; i++) {                          // ! initialization
        head[i].x = 0;
        head[i].next = NULL;
    }

    while (scanf("%s", s) && strcmp(s, "exit")) {
        if (!strcmp(s, "print")) {                      // ? print
            for (int i=0; i<10; i++) {
                printf("%d:", i);
                if ((np = head[i].next)==NULL) {
                    printf(" No card\n");
                    continue;
                }
                while (np!=NULL) {
                    printf(" %d", np->x);
                    np = np->next;
                }
                printf("\n");
            }
        } else if (!strcmp(s, "place")) {               // ? place
            scanf("%d %d", &idx, &len);
            clear(&head[idx]);
            np = head[idx].next = malloc(sizeof(Node));
            for (int i=0; i<len-1; i++) {
                scanf("%d", &np->x);
                np = np->next = malloc(sizeof(Node));
            }
            scanf("%d", &np->x);
            np->next = NULL;
        } else if (!strcmp(s, "all")) {
            scanf("%d %d", &num, &len);
            for (int i=0; i<10; i++) {
                clear(&head[i]);
                np = head[i].next = malloc(sizeof(Node));
                for (int j=0; j<len-1; j++) {
                    np->x = num;
                    np = np->next = malloc(sizeof(Node));
                }
                np->x = num;
                np->next = NULL;
            }
        } else if (!strcmp(s, "swap")) {
            scanf("%d %d", &idx, &idx2);
            np = head[idx].next;
            head[idx].next = head[idx2].next;
            head[idx2].next = np;
        } else if (!strcmp(s, "clear")) {
            for (int i=0; i<10; i++) {
                clear(&head[i]);
            }
        }
    }
}

void clear(Node *head) {
    Node *np = head->next;
    Node *nq;
    while (np!=NULL) {
        nq = np;
        np = nq->next;
        free(nq);
    }
    head->next = NULL;
}