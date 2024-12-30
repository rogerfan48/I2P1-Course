// 14068 - Good Combination

#include <stdio.h>

int N, M, K;
int arr[10];
int order[10];

int sameArr(int *a, int *b) {
    for (int i=0; i<M; i++) {
        if (a[i] != b[i])
            return 0;
    }
    return 1;
}

int includeSameArr(int *a, int *b, int n) {
    for (int i=0; i<n; i++) {
        if (sameArr(a, (b+M*i)))
            return 1;
    }
    return 0;
}

void sort(int *arr, int n) {
    for (int i=0; i<n; i++) {
        int j = i;
        while (j>0 && arr[j-1]>arr[j]) {
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
}

int nextOrder(int n) {
    if (n<0) return 0;
    if (order[n]==N-(M-n)) {
        return nextOrder(n-1);
    }
    else {
        order[n]++;
        if (n!=M) {
            for (int i=1; i<=(M-n); i++)
                order[n+i] = order[n+i-1]+1;
        }
        return 1;
    }
}

void sol() {
    scanf("%d %d %d", &N, &M, &K);
    int ans[1000][M];
    int ans_num=0;
    for (int i=0; i<N; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, N);
    for (int i=0; i<M; i++) {
        order[i] = i;
    }
    do {
        int tmp=0;
        int now[M];
        for (int i=0; i<M; i++) {
            tmp += arr[order[i]];
            now[i] = arr[order[i]];
        }
        if (tmp == K && !includeSameArr(now, (int *)ans, ans_num)) {
            for (int i=0; i<M; i++) {
                ans[ans_num][i] = now[i];
            }
            ans_num++;
        }
    } while (nextOrder(M-1));
    for (int i=0; i<ans_num; i++) {
        for (int j=0; j<M; j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        sol();
    }
}