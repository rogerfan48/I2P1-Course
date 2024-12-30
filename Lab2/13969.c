// 13969 - Frieren and Magic

#include <stdio.h>

int main(){
    int days;
    scanf("%d", &days);
    
    double year = (double)days / (double)365;
    float year2 = (float)days / (float)365;
    long long int seconds = (long long)days * 24 * 3600;

    printf("%.6lf %.6f %lld\n", year, year2, seconds);  
}