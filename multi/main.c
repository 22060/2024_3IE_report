#include <stdio.h>
#include <stdlib.h>
// #include <rngd.h>
#include <time.h>
#include "mulprec.h"
int main()
{
    struct Number a;
    struct Number b;
    // srand(time(NULL));
    printf("%d\n", sizeof(char));
    init_genrand((unsigned long)time(NULL));
    clearByZero(&a);
    clearByZero(&b);
    a.n[0] = 0;
    a.n[1] = 1;
    a.n[KETA - 1] = 1;
    a.sgn = PLUS;
    printf("a = ");
    // dispNumber(&a);
    printf("\n");
    setRnd(&a, 50000);
    printf("b = ");
    // dispNumber(&b);
    printf("\n");
    if (mulBy10(&a, &b) == -1)
    {
        printf("ERROR\n");
    }
    printf("b = ");
    // dispNumber(&b);
    printf("\n");
    while (isZero(&b) == -1)
    {
        if (divBy10(&b, &b) == -1)
        {
            printf("ERROR\n");
        }
        // printf("a = ");
        // dispNumber(&b);
        // printf("\n");
    }
    printf("b = ");
    dispNumber(&b);
    printf("\n");
    return 0;
}
