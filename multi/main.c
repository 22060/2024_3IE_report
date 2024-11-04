#include <stdio.h>

#define KETA 30
#define PLUS 1
#define MINUS -1
typedef struct
{
    int n[KETA];
    int sgn;
} Number;

void clearByZero(Number *a);
void dispNumber(Number *a);

int main(int argc, char *argv[])
{
    Number a;
    Number b;
    clearByZero(&a);
    clearByZero(&b);
    printf("a = ");
    dispNumber(&a);
    printf("\n");
    printf("b = ");
    dispNumber(&b);
    printf("\n");
    return 0;
}

void clearByZero(Number *a)
{
    for (int i = 0; i < KETA; i++)
    {
        a->n[i] = 0;
    }
    a->sgn = 1;
}

void dispNumber(Number *a)
{
    if (a->sgn == PLUS)
    {
        printf("+");
    }
    else
    {
        printf("-");
    }
    for (int i = KETA - 1; i >= 0; i--)
    {
        printf(" %d", a->n[i]);
    }
}