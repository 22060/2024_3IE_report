#include <stdlib.h>
// #include <rngd.h>
#include <stdio.h>
#include <time.h>
#include <MT.h>
#include "mulprec.h"
#define FIBONACCI 0
#define LOOP 1000000
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
    int x = 0;
    int y = 0;
    int z = 0;
    int add_error = 0;
    int sub_error = 0;
    int mul_error = 0;
    int div_error = 0;
    times = (int)time(NULL);
    for (int i = 0; i < LOOP; i++)
    {
        x = (int)genrand_int32() % 100;
        y = (int)genrand_int32() % 100;
        // x = abs(x);
        // y = abs(y);
        // x = 9;
        // y = 1;
        // printf("x = %d, y = %d\n", x, y);
        clearByZero(&a);
        clearByZero(&b);
        clearByZero(&c);
        /*******************************************************************/
        /* setInt test                                                     */
        /*******************************************************************/
        setInt(&a, x);
        setInt(&b, y);
        if (getInt(&a) != x)
        {
            printf("ERROR\n");
            printf("x = %d, a = %d\n", x, getInt(&a));
        }
        if (getInt(&b) != y)
        {
            printf("ERROR\n");
            printf("y = %d, b = %d\n", y, getInt(&b));
        }
        /*******************************************************************/
        /* simpleDivide test                                               */
        /*******************************************************************/
        
        simpleDivide(&a, &b, &c);
        if(y != 0){
            z = x / y;
        }else{
            z = 0;
        }
        if (getInt(&c) != abs(z))
        {
            printf("====================================\n");
            printf("ERROR\n");
            printf("x = %d, y = %d\n", x, y);
            printf("simpleDivide = %d\n", getInt(&c));
            printf("x / y = %d\n", abs(z));
            printf("====================================\n");
            div_error++;
        }
        /*******************************************************************/
        /* multiple test                                                   */
        /*******************************************************************/
        if (multiple(&a, &b, &c) == -1)
        {
            printf("ERROR\n");
        }
        z = x * y;
        if (abs(getInt(&c)) != abs(z))
        {
            printf("====================================\n");
            printf("ERROR\n");
            printf("x = %d, y = %d\n", x, y);
            printf("multiple = %d\n", getInt(&c));
            printf("x * y = %d\n", x * y);
            printf("====================================\n");
        }
        /*******************************************************************/
        /* simpleMultiple test                                             */
        /*******************************************************************/
        if (simpleMultiple(&a, &b, &c) == -1)
        {
            printf("ERROR\n");
        }
        z = x * y;
        if (getInt(&c) != z)
        {
            printf("====================================\n");
            printf("ERROR\n");
            printf("x = %d, y = %d\n", x, y);
            printf("simpleMultiple = %d\n", getInt(&c));
            printf("x * y = %d\n", x * y);
            printf("====================================\n");
            mul_error++;
        }
        /*******************************************************************/
        /* sub test                                                        */
        /*******************************************************************/
        if (sub(&a, &b, &c) == -1)
        {
            printf("ERROR\n");
        }
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
            sub_error++;
        }
        /*******************************************************************/
        /* add test                                                        */
        /*******************************************************************/
        if (add(&a, &b, &c) == -1)
        {
            printf("ERROR\n");
        }
        z = x + y;
        // printf("c = %d\n", getInt(&c));
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
        /*******************************************************************/
        /* numComp test                                                    */
        /*******************************************************************/
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
    times = (int)time(NULL) - times;
    printf("--------------------\n");
    printf("LOOP = %d\n", LOOP);
    printf("add error = %d\n", add_error);
    printf("sub error = %d\n", sub_error);
    printf("mul error = %d\n", mul_error);
    printf("div error = %d\n", div_error);
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
    times = (int)time(NULL);
    for (int i = 0; i < FIBONACCI - 1; i++)
    {
        add(&a, &b, &c);
        copyNumber(&b, &a);
        copyNumber(&c, &b);
        // printf("%d = %d\n", i+2, getInt(&c));
    }
    times = (int)time(NULL) - times;
    setSign(&c, isZero(&c));
    printf("Fibonacci(%d) = ", FIBONACCI);
    dispNumber(&c);
    printf("\n");
    printf("time = %d\n", times);
    return 0;
}
