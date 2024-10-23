#include <stdio.h>
#include <math.h>
int main(void){
    float a;
    float b;
    float c = 1.6;
    float eps = 1.0e-6;
    int n;

    a = 0.0;
    n = 0;
    printf("join loop 1 \n");
    while(1){
        n++;
        a += 0.1;
        b = fabs(c - a);
        if(b < eps)break;
    }
    printf("exit loop1 at %d\n", n);
    a = 0.0;
    n = 0;
    printf("join loop 2 \n");
    while(1){
        n++;
        a += 0.1;
        if(a == c)break;
    }
    printf("exit loop2 at %d\n", n);
}