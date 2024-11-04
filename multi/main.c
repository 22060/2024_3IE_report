#include <stdio.h>
#include <stdlib.h>
// #include <rngd.h>
#include <time.h>

#define KETA 30
#define PLUS 1
#define MINUS -1
struct Number
{
    int n[KETA];
    int sgn;
};

void clearByZero(struct Number *a);
void dispNumber(const struct Number *a);
void setRnd(struct Number *a, int keta);

int main()
{
    struct Number a;
    struct Number b;
    srand(time(NULL));
    clearByZero(&a);
    clearByZero(&b);
    a.n[0] = 7;
    a.n[1] = 4;
    a.n[KETA - 1] = 1;
    setRnd(&b, 10);
    printf("a = ");
    dispNumber(&a);
    printf("\n");
    printf("b = ");
    dispNumber(&b);
    printf("\n");
    return 0;
}

void clearByZero(struct Number *a)
{
    for (int i = 0; i < KETA; i++)
    {
        a->n[i] = 0;
    }
    a->sgn = 1;
}

void dispNumber(const struct Number *a)
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

void setRnd(struct Number *a, int keta)
{
    for (int i = 0; i < keta; i++)
    {
        a->n[i] = rand() % 10;
    }
}