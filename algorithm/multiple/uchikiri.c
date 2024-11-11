#include <stdio.h>
#include <math.h>
#define M_PI		3.14159265358979323846

int main(void){
    double t;
    double eps;
    int n;
    double a;
    double b;

    n = 1;
    a = 0.0;
    eps = 1.0e-6;
    t = M_PI * M_PI / 6.0;

    while(1){
        b = 1.0 / (double)(n*n);
        if(fabs(b) < eps)break;
        a += b;
        printf("sum of %d eq %13.10f , error is %13.10f\n", n, a, fabs(t - a));
        n++;
    }
    return 0;
}