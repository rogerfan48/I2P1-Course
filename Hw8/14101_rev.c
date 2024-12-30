#include <string.h>

void SwapString(char **str1, char **str2) {
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

int Partition(char **A, int l, int r) {
    if (r==l) return l;
    int i = l;
    int j = r;
    int pivot = r;
    while (i<j) {
        while (strcmp(A[i], A[pivot])<=0 && i<j) i++;
        while (strcmp(A[j], A[pivot])>=0 && i<j) j--;
        SwapString(&A[i], &A[j]);
    }
    SwapString(&A[i], &A[pivot]);

    return i;
}