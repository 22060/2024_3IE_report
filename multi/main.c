#include <stdlib.h>
// #include <rngd.h>
#include <stdio.h>
#include <time.h>
#include <MT.h>
#include "mulprec.h"
#define FIBONACCI 0
#define LOOP 10000
int main()
{
    struct Number a;
    struct Number b;
    struct Number c;
    int times = 0;
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
    int z = 0;
    int add_error = 0;
    int sub_error = 0;
    times = time(NULL);
    for (int i = 0; i < LOOP; i++)
    {
        x = (int)genrand_int32() %10000;
        y = (int)genrand_int32() %10000;
        // x = abs(x);
        // y = abs(y);
        // x = 10;
        // y = 5;
        // printf("x = %d, y = %d\n", x, y);
        clearByZero(&a);
        clearByZero(&b);
        clearByZero(&c);
        setInt(&a, x);
        setInt(&b, y);
        if(getInt(&a) != x){
            printf("ERROR\n");
            printf("x = %d, a = %d\n", x, getInt(&a));
        }
        if(getInt(&b) != y){
            printf("ERROR\n");
            printf("y = %d, b = %d\n", y, getInt(&b));
        }
        // printf("a = %d, b = %d\n", getInt(&a), getInt(&b));
        // printf("x = %d, a = %d \n", x, getInt(&a));
        // printf("x - a = %d\n", x - getInt(&a));
        // printf("sub test %d\n", sub(&a, &b, &c));
        if (sub(&a, &b, &c) == -1)
        {
            printf("ERROR\n");
        }
        // setSign(&c, PLUS);
        z = x - y;
        if (getInt(&c) - z != 0)
        {
            printf("====================================\n");
            printf("x = %d,y = %d\n", x, y);
            printf("a - b = %d\n", getInt(&c));
            printf("x - y = %d\n", z);
            printf("(a - b) - (x - y) = %d\n", getInt(&c) - (z));
            printf("ERROR\n");
            printf("====================================\n");
        }
        if (add(&a, &b, &c) == -1)
        {
            printf("ERROR\n");
        }
        // setSign(&c, PLUS);
        z = x + y;
        if (getInt(&c) - (x + y) != 0)
        {
            printf("___________________________________\n");
            printf("x = %d,y = %d\n", x, y);
            printf("a + b = %d\n", getInt(&c));
            printf("sign c = %d\n", getSign(&c));
            printf("x + y = %d\n", z);
            printf("(a + b) - (x + y) = %d\n", getInt(&c) - z);
            printf("___________________________________\n");
            printf("ERROR\n");
            add_error++;
        }
        // printf("x = %d,y = %d\n", x, y);
        // printf("a + b = %ld\n", getInt(&c));
        // printf("x + y = %ld\n", x + y);
        // printf("(a + b) - (x + y) = %ld\n", getInt(&c) - (x + y));
        // printf("a = ");
        // dispNumber(&a);
        // printf("\n");
        // printf("x = %d\n", x);
        if (x > y)
        {
            if (numComp(&a, &b) != 1)
            {
                printf("ERROR in numComp x > y\n");
                printf("x = %d, y = %d\n", x, y);
                printf("a = %d, b = %d\n", getInt(&a), getInt(&b));
            }
        }
        else if (x == y)
        {
            setInt(&a, x);
            setInt(&b, y);
            if (numComp(&a, &b) != 0)
            {
                printf("ERROR in numComp x == y\n");
                printf("x = %d, y = %d\n", x, y);
                printf("a = %d, b = %d\n", getInt(&a), getInt(&b));
            }
        }
        else
        {
            setInt(&a, x);
            setInt(&b, y);
            if (numComp(&a, &b) != -1)
            {
                printf("ERROR in numComp x < y\n");
                printf("x = %d, y = %d\n", x, y);
                printf("a = %d, b = %d\n", getInt(&a), getInt(&b));
            }
        }
    }
    times = time(NULL) - times;
    printf("--------------------\n");
    printf("LOOP = %d\n", LOOP);
    printf("add error = %d\n", add_error);
    printf("sub error = %d\n", sub_error);
    printf("time = %d\n", times);
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
    times = time(NULL);
    for (int i = 0; i < FIBONACCI - 1; i++)
    {
        add(&a, &b, &c);
        copyNumber(&b, &a);
        copyNumber(&c, &b);
        // printf("%d = %d\n", i+2, getInt(&c));
    }
    times = time(NULL) - times;
    setSign(&c, isZero(&c));
    printf("Fibonacci(%d) = ", FIBONACCI);
    dispNumber(&c);
    printf("\n");
    printf("time = %d\n", times);
    return 0;
}
