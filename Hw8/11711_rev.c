#include <stdio.h>
#include <stdlib.h>

unsigned*** new_3d_array(unsigned n,unsigned m,unsigned k) {
    unsigned*** ptr = calloc(n+1, sizeof(unsigned**));
    for (int i=0; i<n; i++) {
        ptr[i] = calloc(m+1, sizeof(unsigned*));
        for (int j=0; j<m; j++) {
            ptr[i][j] = calloc(k, sizeof(unsigned));
        }
    }
    return ptr;
}

void delete_3d_array(unsigned ***arr) {
    for (int i=0; arr[i]!=0; i++) {
        for (int j=0; arr[i][j]!=0; j++) {
            free(arr[i][j]);
        }
        free(arr[i]);
    }
    free(arr);
}