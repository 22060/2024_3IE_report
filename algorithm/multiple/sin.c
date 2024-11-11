#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
// #define M_PI		3.14159265358979323846
int facto(int n)
{
int i,ans;
ans=1;
for(i=1;i<=n;i++) {
ans=ans*i;
}
return ans;
}

int main(void){
    double t;
    double eps;
    int n;
    double a;
    double b;
    float x = 2.0;

    n = 0;
    a = 0.0;
    eps = 1.0e-2;
    t = sin(x);

    while(1){
        b = ((double)((n%2)?-1:1) / ((double)facto(2*n+1))) * ((double)pow(x,(double)(2*n+1)));
        printf("%f\n",b);
        if(fabs(b) < eps)break;
        a += b;
        printf("sum of %d eq %13.10f , error is %13.10f\n", n, a, fabs(t - a));
        n++;
    }
    printf("n = %d\n", n);
    return 0;
}