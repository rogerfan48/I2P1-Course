#include <stdio.h>
#include <stdlib.h>

void merge(int*, int, int, int);
void mergeSort(int*, int, int);
void printArray(int[] , int);

void merge(int* arr, int l, int m, int r) {
    int i, j, k;
    int *a = malloc((r-l+1) * sizeof(int));
    for (i=l, j=m+1, k=0; k<(r-l+1); k++) {
        a[k] =  (i==m+1) ? arr[j++] :
                (j==r+1) ? arr[i++] :
                (arr[i] < arr[j]) ? arr[i++] : arr[j++];
    }
    for (i=l, k=0; k<(r-l+1); i++, k++) {
        arr[i] = a[k];
    }
    free(a);
}

void mergeSort(int* arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        printArray(arr + l, m - l + 1);

        mergeSort(arr, m + 1, r);
        printArray(arr + m + 1, r - m);

        merge(arr, l, m, r);
    }
}

void printArray(int A[], int size) {
    int i;
    for (i = 0; i < size; i++){
        if(i != 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}

int main() {
    int size;
    scanf("%d", &size);

    int *arr = (int*)malloc(sizeof(int)*size);
    
    for(int i = 0; i < size; i++){
        int num;
        scanf("%d", &num);
        arr[i] = num;
    }

    mergeSort(arr, 0, size - 1);
    
    printArray(arr, size);
    return 0;
}