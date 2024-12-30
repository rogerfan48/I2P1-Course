// 13969 - Frieren and Magic

// *******
//
// * see "Lab2"
//
// *******

#include <stdio.h>

int main() {
    long x;
    double y_d;
    float y_f;
    long s;

    scanf("%ld", &x);
    y_d = x/(double)365;
    y_f = x/(float)365;
    s = x*24*3600;

    printf("%.6f %.6f %ld\n", y_d, y_f, s);

    return 0;

}