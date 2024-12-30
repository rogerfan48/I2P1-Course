#include <stdio.h>
#include <string.h>

// from here on
#include <stdlib.h>

typedef struct node {
    int idx;
    struct node* next;
} Node;

void AddBack(Node** head, Node** back, int* arr, int n);
void CircularInsert(Node** head, Node** back, int n, int m);

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
void CircularInsert(Node** head, Node** back, int n, int m) {
    Node *now = (*head)->next;
    Node *new;
    int steps;
    for (int i=0; i<n; i++) {
        new = malloc(sizeof(Node));
        new->idx = m;
        new->next = now->next;
        now->next = new;
        if (now == (*back)) {
            (*back) = new;
        }
        steps = now->idx;
        while (steps--) {
            if (now->next == NULL) {
                now = (*head)->next;
            } else {
                now = now->next;
            }
        }
    }
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
        } else if (!strcmp(str, "CircularInsert")) {
            scanf("%d %d", &n, &m);
            
            CircularInsert(&head, &back, n, m);
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