// 14180 - Domo the Super Train Conductor

#include <stdio.h>
#include <string.h>

// partial code from now on
#include <stdlib.h>

typedef struct node {
    int idx;
    struct node* next;
} Node;

void AddBack(Node** head, Node** back, int* arr, int n);
void CircularInsert(Node** head, Node** back, int n, int m);
void print(Node** head);

void AddBack(Node** head, Node** back, int* arr, int n) {
    for (int i=0; i<n; i++) {
        Node* new = malloc(sizeof(Node));
        new->idx = arr[i];
        new->next = NULL;
        (*back) = (*back)->next = new;
    }
}
void CircularInsert(Node** head, Node** back, int n, int m) {
    int step;
    Node* now = (*head)->next;
    for (int i=0; i<n; i++) {
        Node* new = malloc(sizeof(Node));
        new->idx = m;
        new->next = now->next;
        now->next = new;
        if (now == (*back)) {       // !!!
            (*back) = new;
        }
        step = now->idx;
        while (step--) {
            if (now->next==NULL) {
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
            print(&head);
        } else if (!strcmp(str, "CircularInsert")) {
            scanf("%d %d", &n, &m);
            
            CircularInsert(&head, &back, n, m);
            print(&head);
        }
    }
    
    // print all the element except the dummy head and free them.
    print(&head);
    // Node* print = head;
         
    // if (head->next == NULL) printf("empty\n");
    
    // while (print != NULL) {
    //     if (print->idx != -1)
    //         printf("%d%c", print->idx, (print->next == NULL ? '\n' : ' '));
        
    //     Node* del = print;
    //     print = print->next;
    //     free(del);
    // }
}

void print(Node** head) {
    Node* print = malloc(sizeof(Node));
    print = *head;
         
    if ((*head)->next == NULL) printf("empty\n");
    else printf(">>> ");
    
    while (print != NULL) {
        if (print->idx != -1)
            printf("%d%c", print->idx, (print->next == NULL ? '\n' : ' '));
        
        print = print->next;
    }
}