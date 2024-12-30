// 13420 - Domo travels around the world

#include <stdio.h>
#include <stdlib.h>

int N, K;
bool visited[100] = {0};
int (*bond)[2];

int findUnvisited();
void visitThem(int x);

int main() {
    int ans=-1, x;
    scanf("%d %d", &N, &K);
    bond = malloc(2*K*sizeof(int));
    for (int i=0; i<K; i++) {
        scanf("%d %d", &bond[i][0], &bond[i][1]);
    }

    while ((x = findUnvisited()) != -1) {
        visitThem(x);
        ans++;
    }

    printf("%d\n", ans);
}

int findUnvisited() {
    for (int i=0; i<N; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            return i;
        }
    }
    return -1;
}

void visitThem(int x) {
    for (int i=0; i<K; i++) {
        if (bond[i][0]==x)
            if (!visited[bond[i][1]]) {         // ! keep visit the cities which can directly connect to
                visited[bond[i][1]] = 1;
                visitThem(bond[i][1]);
            }
        if (bond[i][1]==x)
            if (!visited[bond[i][0]]) {
                visited[bond[i][0]] = 1;
                visitThem(bond[i][0]);
            }
    }
}