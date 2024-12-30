#include <stdio.h>

int n, ans=0;
int arr[10];
int ban[10][10];

int valid(int a, int b);
void place(int level);

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) {
            scanf("%1d", &ban[i][j]);
        }
    place(0);
    printf("%d\n", ans);
}

int valid(int a, int b) {
    if (ban[a][b]) return 0;
    for (int i=0; i<a; i++) {
        if (arr[i]==b || arr[i]==(b-a+i) || arr[i]==(b+a-i))  // ! a bit complex
            return 0;
    }
    return 1;
}

void place(int level) {
    if (level == n) {
        ans++;
        return;
    }
    for (int i=0; i<n; i++) {
        if (valid(level, i)) {
            arr[level] = i;
            place(level+1);
        }
    }
}