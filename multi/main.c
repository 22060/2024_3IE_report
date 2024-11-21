#include <stdlib.h>
// #include <rngd.h>
#include <time.h>
#include <MT.h>
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
    for (int i = 0; i < 10000000; i++)
    { // setint getint check
        // x = genrand_int32();
        // if (setInt(&a, x) == -1)
        // {
        //     printf("ERROR in setInt\n");
        // }
        // else
        // {
        //     if (getInt(&a) != x)
        //     {
        //         printf("ERROR in comp x and multiple array\n");
        //     }
        // }

        // numconp test
        x = genrand_int32();
        y = genrand_int32();
        printf("x = %d, y = %d ", x, y);
        setInt(&a, x);
        setInt(&b, y);
        printf("a = %d\n", numComp(&a, &b));
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
                // printf("ERROR in numComp\n");
            }
        }
        else
        {
            setInt(&a, x);
            setInt(&b, y);
            if (numComp(&a, &b) != -1)
            {
                // printf("ERROR in numComp\n");
            }
        }
    }

    printf("a = ");
    dispNumber(&a);
    printf("\n");
    return 0;
}
