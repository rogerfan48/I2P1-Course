// 12934 - Rotate Numbers

#include <stdio.h>

int main() {
    int i, n=0, start=0;
    int arr[101] = {};                                  // ! same here
    int R[10] = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
    
    for (i=0; i<101; i++) {                             // ! 101, then it can detect EOF when len=100
        if (scanf("%1d", &arr[i])==EOF) {
            n = i;
            break;
        }
        if (R[arr[i]]==-1) {
            printf("No\n");
            return 0;
        }
    }

    for (i=n-1; i>=0; i--) {
        if (!R[arr[i]] && !start) {
            continue;
        } else {
            start = 1;
            printf("%1d", R[arr[i]]);
        }
    }
    printf("\n");
}