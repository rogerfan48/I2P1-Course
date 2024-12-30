// 14019 - Max Pooling

#include <stdio.h>
#include <math.h>
#define SIZE 2400

int ori[SIZE][SIZE] = {0};
int arr[SIZE][SIZE] = {0};

int main() {
    int i, j, l, f, g;
    int t, n, m, k, r, p, s, temp;
    scanf("%d", &t);

    for (i=0; i<t; i++) {
        for (j=0; j<SIZE; j++) {                // ! reset ori array
            for (l=0; l<SIZE; l++) {
                ori[j][l] = 0;
            }
        }
        scanf("%d %d %d %d %d %d", &n, &m, &k, &r, &p, &s);
        int len1 = n+2*p;
        int len2 = ceil(((double)len1-m+1)/s);
        int len3 = ceil((double)len2/k);
        int con[m][m];
        int arr2[len2][len2];
        int arr3[len3][len3];

        for (j=p; j<n+p; j++) {
            for (l=p; l<n+p; l++) {
                scanf("%d", &ori[j][l]);
            }
        }
        for (j=0; j<m; j++) {
            for (l=0; l<m; l++) {
                scanf("%d", &con[j][l]);
            }
        }

        if (r%4==0) {
            for (j=0; j<len1; j++) {
                for (l=0; l<len1; l++) {
                    arr[j][l] = ori[j][l];
                }
            }
        } else if (r%4==1) {
            for (j=0; j<len1; j++) {
                for (l=0; l<len1; l++) {
                    arr[j][l] = ori[len1-l-1][j];
                }
            }
        } else if (r%4==2) {
            for (j=0; j<len1; j++) {
                for (l=0; l<len1; l++) {
                    arr[j][l] = ori[len1-j-1][len1-l-1];
                }
            }
        } else {
            for (j=0; j<len1; j++) {
                for (l=0; l<len1; l++) {
                    arr[j][l] = ori[l][len1-j-1];
                }
            }
        }

        // for (j=0; j<len1; j++) {
        //     for (l=0; l<len1; l++) {
        //         printf("%d ", arr[j][l]);
        //     }
        //     printf("\n");
        // }

        for (j=0; j<len2; j++) {
            for (l=0; l<len2; l++) {
                temp=0;
                for (f=0; f<m; f++) {
                    for (g=0; g<m; g++) {
                        temp += arr[j*s+f][l*s+g]*con[f][g]; // ! s
                    }
                }
                arr2[j][l] = temp;
            }
        }

        // for (j=0; j<len2; j++) {
        //     for (l=0; l<len2; l++) {
        //         printf("%d ", arr2[j][l]);
        //     }
        //     printf("\n");
        // }

        for (j=0; j<len3; j++) {
            for (l=0; l<len3; l++) {
                temp = arr2[j*k][l*k];
                for (f=0; f<k; f++) {
                    for (g=0; g<k; g++) {
                        if ((j*k+f)>=len2 || (l*k+g)>=len2) continue;
                        if (arr2[j*k+f][l*k+g]>temp)
                            temp = arr2[j*k+f][l*k+g];
                    }
                }
                arr3[j][l] = temp;
            }
        }

        for (j=0; j<len3; j++) {
            for (l=0; l<len3; l++) {
                printf("%d ", arr3[j][l]);
            }
            printf("\n");
        }
    }
}
