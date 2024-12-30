#include <stdlib.h>

typedef struct node {
    int idx;
    struct node* next;
} Node;

void AddBack(Node** head, Node** back, int* arr, int n);
void CircularInsert(Node** head, Node** back, int n, int m);