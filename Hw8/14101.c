#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void SwapString(char **str1, char **str2) {
    char* temp;
    temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

int Partition(char **A, int l, int r) {
    if (r-l==0) return r;
    int i = l;
    int j = r;
    int pivot = r;

    while (i<j) {
        while (!(strcmp(A[i], A[pivot]) > 0) && (i<j)) i++;
        while (!(strcmp(A[j], A[pivot]) < 0) && (i<j)) j--;
        SwapString(&A[i], &A[j]);
    }
    SwapString(&A[i], &A[pivot]);

    return j;
}

char* Select(char **A, int l, int r, int k) {
    while(l < r) {
        int m = Partition(A, l, r);
        if(m == k)
            return A[m];
        if(m < k)
            l = m+1;
        else
            r = m-1;
    }
    return A[l];
}


int main() {
    int N, k;
    char buff[1000];
    scanf("%d\n", &N);
    char **Names = (char**)malloc(N * sizeof(char*));
    for(int i = 0; i < N; i++) {
        gets(buff);
        Names[i] = (char*)malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(Names[i], buff);
    }

    scanf("%d", &k);
    printf("%s\n", Select(Names, 0, N-1, k-1));

    for(int i = 0; i < N; i++) {
        free(Names[i]);
    }

    free(Names);
}
