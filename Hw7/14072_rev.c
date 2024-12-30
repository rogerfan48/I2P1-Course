#include <stdio.h>

double x[4];
int found;

void dfs(double *now, int len) {
    if (found) return;
    if (len==1) {
        found |= (now[0]==24);
        return;
    }
    double tmp[4];
    for (int i=0; i<len-1; i++) {
        for (int j=0; j<len-1; j++)
            tmp[j] = now[j + (j>i)];
        tmp[i] = now[i] + now[i+1];
        dfs(tmp, len-1);
        tmp[i] = now[i] - now[i+1];
        dfs(tmp, len-1);
        tmp[i] = now[i] * now[i+1];
        dfs(tmp, len-1);
        if (now[i+1] == 0) continue;
        tmp[i] = now[i] / now[i+1];
        dfs(tmp, len-1);
    }
}

void sol() {
    found = 0;
    double now[4];

    for (int i=0; i<4; i++) {
        scanf("%lf", &x[i]);
    }
    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            for (int k=0; k<4; k++)
                for (int l=0; l<4; l++) {
                    if (i==j || i==k || i==l || j==k || j==l || k==l) continue;
                    now[0]=x[i]; now[1]=x[j]; now[2]=x[k]; now[3]=x[l];
                    dfs(now, 4);
                }

    if (found) printf("Safe\n");
    else printf("Disqualified\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        sol();
    }
}