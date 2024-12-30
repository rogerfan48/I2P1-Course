// 11711 - Dynamic 3D array

#include <stdlib.h>

// ! version 1:
unsigned*** new_3d_array(unsigned n,unsigned m,unsigned k) {
    unsigned*** ptr3 = malloc((n+1)*sizeof(unsigned**));
    for (int i=0; i<n; i++) {
        unsigned** ptr2 = malloc((m+1)*sizeof(unsigned*));
        ptr2[m] = 0;
        ptr3[i] = ptr2;
        for (int j=0; j<m; j++) {
            unsigned* ptr1 = malloc((k+1)*sizeof(unsigned));
            ptr2[j] = ptr1;
        }
    }
    ptr3[n] = 0;
    return ptr3;
}

void delete_3d_array(unsigned ***arr) {
    int i=0;
    while (arr[i]!=0) {
        int j=0;
        while (arr[i][j]!=0) {
            free(arr[i][j]);
            j++;
        }
        free(arr[i]);
        i++;
    }
    free(arr);
}

// ! version 2: with no redundant pointer variable, malloc
unsigned*** new_3d_array(unsigned n,unsigned m,unsigned k) {
    unsigned*** ptr3 = malloc((n+1)*sizeof(unsigned**));
    ptr3[n] = 0;
    for (int i=0; i<n; i++) {
        ptr3[i] = malloc((m+1)*sizeof(unsigned*));
        ptr3[i][m] = 0;
        for (int j=0; j<m; j++) {
            ptr3[i][j] = malloc(k*sizeof(unsigned));
        }
    }
    return ptr3;
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

// ! version 3: calloc
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

// ! version 4: Koying
unsigned*** new_3d_array(unsigned n, unsigned m, unsigned k) {
    // Allocate extra space for dimensions
    unsigned*** ptr3 = malloc(3 * sizeof(unsigned) + n * sizeof(unsigned**));
    
    // Store dimensions at the beginning
    unsigned *dims = (unsigned*)ptr3;
    dims[0] = n;
    dims[1] = m;
    dims[2] = k;
    
    // Adjust ptr3 to point to the actual 3D array part
    ptr3 = (unsigned***)(&dims[3]);

    for (unsigned i = 0; i < n; i++) {
        ptr3[i] = malloc(m * sizeof(unsigned*));
        for (unsigned j = 0; j < m; j++) {
            ptr3[i][j] = malloc(k * sizeof(unsigned));
        }
    }

    return ptr3;
}

void delete_3d_array(unsigned*** arr) {
    // Adjust pointer to read dimensions
    unsigned *dims = ((unsigned*)arr) - 3;
    unsigned n = dims[0];
    unsigned m = dims[1];
    unsigned k = dims[2];

    // Free memory in reverse order
    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = 0; j < m; j++) {
            free(arr[i][j]);
        }
        free(arr[i]);
    }
    
    // Free the memory allocated for dimensions and array pointers
    free(dims);
}