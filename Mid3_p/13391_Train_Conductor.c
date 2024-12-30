// 13391 - Domo the Train Conductor

#include <stdio.h>
#include <string.h>

// ! partial judge from here on:
#include <stdlib.h>

typedef struct node {
    int idx;
    struct node* next;
} Node;

void AddFront(Node** head, Node** back, int num);
void AddBack(Node** head, Node** back, int num);
void DeleteFront(Node** head, Node** back);
void Delete(Node** head, Node** back, int num);
void Swap(Node** head, Node** back);

void AddFront(Node** head, Node** back, int num) {
    if ((*head)->idx == -1) {
        (*head)->idx = num;
    } else {
        Node* new = malloc(sizeof(Node));
        new->idx = num;
        new->next = (*head);
        (*head) = new;
    }
}
void AddBack(Node** head, Node** back, int num) {
    if ((*head)->idx == -1)
        (*head)->idx = num;
    else {
        Node* new = malloc(sizeof(Node));
        new->idx = num;
        new->next = NULL;
        (*back)->next = new;
        (*back) = new;
    }
}
void DeleteFront(Node** head, Node** back) {
    if ((*head)->idx == -1) return;
    if ((*head) == (*back)) {
        (*head)->idx = -1;
        return;                     // !!!
    }
    Node* tmp = (*head)->next;
    free(*head);
    (*head) = tmp;
}
void Delete(Node** head, Node** back, int num) {
    Node* now = (*head);
    Node* tmp;
    if (now->idx == -1) return;
    while (now->idx == num) {
        if (now->next == NULL) {    // !!!
            now->idx = -1;
            (*head) = now;          // !!!
            return;
        }
        tmp = now->next;
        free(now);
        now = tmp;
    }
    (*head) = now;
    while (now->next != NULL) {
        if (now->next->idx == num) {
            tmp = now->next->next;
            free(now->next);
            now->next = tmp;      // !!!
        } else {
            now = now->next;
        }
    }
    (*back) = now;
}
void Swap(Node** head, Node** back) {
    if ((*head) == (*back)) return;
    Node* now = (*back) = (*head);
    Node* before;
    Node* after = now->next;
    now->next = NULL;
    while (after != NULL) {         // !!!
        before = now; now = after; after = now->next;
        now->next = before;
    }
    (*head) = now;
}

int main()
{
    char str[50];
    
    Node* head = (Node*) malloc(sizeof(Node));
    Node* back = head;
    // initialize the dummy head
    
    // we'll append the element after this dummy head to avoid runtime error.
    head->idx = -1;
    head->next = NULL;
    
    while (scanf("%s", str) != EOF) {
        
        int num;
        
        if (!strcmp(str, "AddFront")) {
            scanf("%d", &num);
            AddFront(&head, &back, num);
        }
        else if (!strcmp(str, "AddBack")) {
            scanf("%d", &num);
            AddBack(&head, &back, num);
        }
        else if (!strcmp(str, "DeleteFront")) {
            DeleteFront(&head, &back);
        }
        else if (!strcmp(str, "Delete")) {
            scanf("%d", &num);
            Delete(&head, &back, num);
        }
        else if (!strcmp(str, "Swap")) {
            Swap(&head, &back);
        }
    }
    
    // print all the element except the dummy head and free them.
    Node* print = head;

    if (head->next == NULL) printf("empty\n");
    
    while (print != NULL) {
        if (print->idx != -1)
            printf("%d%c", print->idx, (print->next == NULL ? '\n' : ' '));
        
        Node* del = print;
        print = print->next;
        free(del);
    }
}

// void AddFront(Node** head, Node** back, int num) {
//     if ((*head)->idx == -1) {
//         (*head) = malloc(sizeof(Node));
//         (*head)->idx = num;
//         (*head)->next = (*back);
//         (*back) = (*head);
//     } else {
//         Node* new = malloc(sizeof(Node));
//         new->idx = num;
//         new->next = (*head);
//         (*head) = new;
//     }
// }
// void AddBack(Node** head, Node** back, int num) {
//     if ((*head)->idx == -1)
//         AddFront(head, back, num);
//     else {
//         Node* new = malloc(sizeof(Node));
//         new->idx = num;
//         new->next = (*back)->next;
//         (*back) = (*back)->next = new;
//     }
// }
// void DeleteFront(Node** head, Node** back) {
//     if ((*head)->idx == -1) return;
//     if ((*head) == (*back)) {
//         (*back) = (*back)->next;
//         free(*head);
//         (*head) = (*back);
//     } else {
//         Node* tmp = (*head)->next;
//         free(*head);
//         (*head) = tmp;
//     }
// }
// void Delete(Node** head, Node** back, int num) {
//     if ((*head)->idx == -1) return;
//     Node* now = malloc(sizeof(Node));
//     Node* HEAD = now;
//     Node* tmp;
//     now->idx = 0;
//     now->next = (*head);
//     while (now->next->idx != -1) {
//         if (now->next->idx == num) {
//             tmp = now->next->next;
//             if (now->next == *head) *head = tmp;
//             if (now->next == *back) *back = now;
//             free(now->next);
//             now->next = tmp;
//         } else {
//             now = now->next;
//         }
//     }
//     free(HEAD);
// }
// void Swap(Node** head, Node** back) {
//     if ((*head) == (*back)) return;
//     Node* now = (*back) = (*head);
//     Node* before;
//     Node* after = now->next;
//     now->next = malloc(sizeof(Node));
//     now->next->idx = -1;
//     now->next->next = NULL;
//     while (after->idx != -1) {
//         before = now; now = after; after = now->next;
//         now->next = before;
//     }
//     (*head) = now;
//     free(after);
// }