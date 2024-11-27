#include <stdlib.h>
// #include <rngd.h>
#include <stdio.h>
#include <time.h>
#include <MT.h>
#include "mulprec.h"
int main()
{
    struct Number a;
    struct Number b;
    struct Number c;
    // srand(time(NULL));
    init_genrand((unsigned long)time(NULL));
    clearByZero(&a);
    clearByZero(&b);
    clearByZero(&c);
    a.n[0].value = 0;
    a.n[1].value = 1;
    a.sgn = PLUS;
    printf("a = ");
    // dispNumber(&a);
    printf("\n");
    setRnd(&a, 100000);
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
    // while (isZero(&b) == -1)
    // {
    //     divBy10(&b, &b);
    //     // printf("b = ");
    //     // dispNumber(&b);
    //     // printf("\n");
    // }
    int x = 0;
    int y = 0;
    for (int i = 0; i < 1; i++)
    {
        x = (int)genrand_int32();
        y = (int)genrand_int32();
        x = abs(x);
        y = abs(y);
        // x = 10;
        // y = 5;
        printf("x = %d, y = %d\n", x, y);
        clearByZero(&a);
        clearByZero(&b);
        clearByZero(&c);
        setInt(&a, x);
        setInt(&b, y);
        printf("a = %d, b = %d\n", getInt(&a), getInt(&b));
        printf("a = ");
        // dispNumber(&a);
        printf("\n");
        printf("b = ");
        // dispNumber(&b);
        printf("\n");
        // printf("x = %d, a = %d \n", x, getInt(&a));
        // printf("x - a = %d\n", x - getInt(&a));
        printf("sub test %d\n", sub(&a, &b, &c));
        // printf("c = ");
        // dispNumber(&c);
        // printf("\n");
        setSign(&c, PLUS);
        printf("a + b = %ld\n", getInt(&c));
        printf("x + y = %ld\n", abs(x) - abs(y));
        // printf("a = ");
        // dispNumber(&a);
        // printf("\n");
        // printf("x = %d\n", x);
        if (x > y)
        {
            if (numComp(&a, &b) != 1)
            {
                printf("ERROR in numComp\n");
            }
        }
        else if (x == y)
        {
            setInt(&a, x);
            setInt(&b, y);
            if (numComp(&a, &b) != 0)
            {
                printf("ERROR in numComp\n");
            }
        }
        else
        {
            setInt(&a, x);
            setInt(&b, y);
            if (numComp(&a, &b) != -1)
            {
                printf("ERROR in numComp\n");
            }
        }
    }
    printf("--------------------\n");
    int f0 = 0;
    int f1 = 1;
    clearByZero(&a);
    clearByZero(&b);
    clearByZero(&c);
    setInt(&a, f0);
    setInt(&b, f1);
    setSign(&a, PLUS);
    setSign(&b, PLUS);
    setSign(&c, PLUS);
    for(int i=0;i < 0;i++){
        add(&a, &b, &c);
        copyNumber(&b, &a);
        copyNumber(&c, &b);
        // printf("%d = %d\n", i+2, getInt(&c));
    }
    printf("Fibonacci(1000) = ");
    // dispNumber(&c);
    printf("\n");
    return 0;
}
