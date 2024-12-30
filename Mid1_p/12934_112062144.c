// 12934 - Rotate Numbers

#include <stdio.h>
#include <string.h>

int main() {
    int i, n, start=0;
    char original[101];
    int arr[100] = {};
    int R[10] = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};

    scanf("%s", original);
    n = strlen(original);
    for (i=0; i<n; i++) {
        arr[i] = original[i] - '0';
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