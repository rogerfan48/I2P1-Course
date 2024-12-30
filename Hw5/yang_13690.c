// 13690 - Bad Fibonacci's soup

#include <stdio.h>
#define int long long                       // ! 此題用 int 不夠大 用這句，要記得把 int main 改成 signed main

int a, b, c, d, n;
int recordF[81] = {0};
int isRecordF[81] = {0};
int recordG[81] = {0};
int isRecordG[81] = {0};

int f(int);
int g(int);

signed main() {
    scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &d, &n);
    recordF[0] = a; isRecordF[0] = 1;
    recordF[1] = b; isRecordF[1] = 1;
    recordG[0] = c; isRecordG[0] = 1;
    recordG[1] = d; isRecordG[1] = 1;
    
    printf("%lld %lld\n", f(n), g(n));
}

int f(int x) {
    if (isRecordF[x]) return recordF[x];
    if (x%3 == 0) {                         // ! 不能寫成 !x%3 因為優先序會誤以為是 (!x)%3 而非 !(x%3)
        recordF[x] = f(x-1) + g(f(x/3)%x);
    } else {
        recordF[x] = f(x-1) + g(x-2);
    }
    isRecordF[x] = 1;
    return recordF[x];
}
int g(int x) {
    if (isRecordG[x]) return recordG[x];
    if (x%5 == 0) {
        recordG[x] = g(x-1) + f(g(x/5)%x);
    } else {
        recordG[x] = g(x-1) + f(x-2);
    }
    isRecordG[x] = 1;
    return recordG[x];
}