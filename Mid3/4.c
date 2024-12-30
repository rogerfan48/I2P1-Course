#include <stdio.h>
#include <string.h>

// from here on
#include <stdlib.h>

typedef struct node {
    int idx;
    struct node* next;
} Node;

void AddBack(Node** head, Node** back, int* arr, int n);
void LinearDelete(Node** head, Node** back);

void AddBack(Node** head, Node** back, int* arr, int n) {
    Node *now, *new;
    now = (*back);
    for (int i=0; i<n; i++) {
        new = malloc(sizeof(Node));
        new->idx = arr[i];
        now = now->next = new;
    }
    now->next = NULL;
    (*back) = now;
}
void LinearDelete(Node** head, Node** back) {
    Node *now = (*head);
    Node *del;
    int steps;
    while (now->next != NULL) {
        del = now->next;
        now->next = del->next;
        steps = del->idx;
        if (del == (*head)) {
            if (del->next==NULL) {
                (*back) = del;
                del->idx = -1;
                return;
            }
            (*head) = del->next;
        }
        free(del);
        if (steps != 1) {
            for (int i=0; i<(steps-1); i++) {
                if (now->next == NULL) goto bb;
                now = now->next;
            }
        }
    }
    bb:
    now = (*head);
    while (now->next != NULL) {
        now = now->next;
    }
    (*back) = now;
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
        
        int n, m;
        
        if (!strcmp(str, "AddBack")) {
            scanf("%d", &n);
            
            int* arr = (int*) malloc(sizeof(int) * n);
            for (int i = 0; i < n; i++) {
                scanf("%d", &arr[i]);
            }
            
            AddBack(&head, &back, arr, n);
            free(arr);
        } else if (!strcmp(str, "LinearDelete")) {
            LinearDelete(&head, &back);
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