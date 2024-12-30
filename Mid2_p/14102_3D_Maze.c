// 14102 - Domo's 3D Maze

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define int long long
#define min(a,b,c) (((((a)<(b))?(a):(b))<(c)) ? (((a)<(b))?(a):(b)) : (c))

int N, M, K;
int ans=LLONG_MAX;
int *maze, *dp;

int move(int a, int b, int c);

signed main() {
    scanf("%lld %lld %lld", &N, &M, &K);
    maze = malloc(N * M * K * sizeof(long long));
    dp = calloc(N * M * K, sizeof(long long));
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            for (int k=0; k<K; k++) {
                scanf("%lld", &maze[i*M*K+j*K+k]);
            }
    dp[0] = maze[0];                                                    // 最初點值

    printf("%lld\n", move(N-1, M-1, K-1));
}

int move(int a, int b, int c) {
    if (a<0 || b<0 || c<0) return LLONG_MAX;                            // 超出邊界
    if (maze[a*M*K+b*K+c] == -1) return LLONG_MAX;                      // 障礙物

    int temp = dp[a*M*K+b*K+c];                                         // 算過就用算過的
    if (temp) return temp;

    temp = min(move(a-1,b,c), move(a,b-1,c), move(a,b,c-1));            // ! 若無路可至此 設為不可到達
    return dp[a*M*K+b*K+c] = ((temp==LLONG_MAX) ? LLONG_MAX : (temp + maze[a*M*K+b*K+c]));
}