#include <stdio.h>

int main(void){
    int i;
    double s1 = 0.0;
    double s2 = 0.0;
    double c;
    double t,y;

    for ( i = 0; i < 500000000; i++)
    {
        s1 += 0.3;
    }

    c = 0.0;
    for ( i = 0; i < 500000000; i++)
    {
        y = 0.3 - c;
        t = s2 + y;
        c = (t - s2) - y;
        s2 = t;
    }

    printf("s1 = %23.15lf\n", s1);
    printf("s2 = %23.15f\n", s2);
    return 0;    
    
}