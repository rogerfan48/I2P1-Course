// 14182 - Dad, don't do that

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char idx;
    struct Node* next;
} Node;

Node* top;
char str[1000005];
int K, pos=0, len;

void push(char x);
char read();
char get();
int isBlank();
void print();

int main() {
    top = malloc(sizeof(Node));
    top->idx = 0;
    top->next = NULL;

    char c;
    while ((c = getchar()) != '\n') {
        str[pos++] = c;
    }
    str[pos] = '\0';
    len = pos;
    scanf("%d", &K);

    for (int i=0; i<len; i++) {
        if (isBlank() || K==0) {
            push(str[i]);
            continue;
        }
        while (K>=0) {
            if (isBlank() || K==0) {
                push(str[i]);
                break;
            } else if (str[i] < read()) {
                get();
                K--;
            } else {
                push(str[i]);
                break;
            }
        }
    }
    print();
}

void push(char x) {
    if (top->idx == 0) {
        top->idx = x;
    } else {
        Node* new = malloc(sizeof(Node));
        new->idx = x;
        new->next = top;
        top = new;
    }
}

char read() {
    return top->idx;
}

char get() {        // ! need ensuring not blank
    char ans = top->idx;
    if (top->next == NULL) {
        top->idx = 0;
        return ans;
    }
    Node* tmp = top->next;
    free(top);
    top = tmp;
    return ans;
}

int isBlank() {
    return (top->idx == 0) ? 1 : 0;
}

void print() {
    int begin = 0;
    Node* now = top;
    if (now->idx == 0) {
        printf("0\n");
    } else if (now->next == NULL) {
        printf("%c\n", now->idx);
    } else {
        char* ans = malloc(len*sizeof(char));
        pos = 0;
        while (now->next != NULL) {
            ans[pos++] = now->idx;
            now = now->next;
        }
        ans[pos] = now->idx;
        for (int i=pos; i>=0; i--) {
            if (!begin && ans[i]=='0') continue;
            begin = 1;
            printf("%c", ans[i]);
        }
        printf("\n");
    }
}