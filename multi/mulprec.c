#include "mulprec.h"
#include <stdio.h>
#include <MT.h>
int numcol[10] = {0, 31, 32, 33, 34, 91, 92, 93, 94, 95};
int divBy10(const struct Number *a, struct Number *b)
{
    int i;
    if (a->sgn == ZERO)
    {
        clearByZero(b);
        return 0;
    }
    b->n[KETA - 1] = 0;
    for (i = 0; i < KETA - 1; i++)
    {
        b->n[i] = a->n[i + 1];
    }
    b->sgn = a->sgn;
#if KETA >= 8
    int flag = 0;
    for (i = 0; i < KETA / 8; i++)
    {
        if (b->lli[i] != 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        b->sgn = ZERO;
    }
#else
    if (b->lli[0] == 0)
    {
        b->sgn = ZERO;
    }
#endif

    return 0;
}
int mulBy10(const struct Number *a, struct Number *b)
{
    int i;
    if (a->sgn == ZERO)
    {
        clearByZero(b);
        return 0;
    }
    b->n[0] = 0;
    for (i = 0; i < KETA - 1; i++)
    {
        b->n[i + 1] = a->n[i];
    }
    b->n[KETA - 1] = 0;
    b->sgn = a->sgn;
    if (a->n[KETA - 1] != 0)
    {
        // b->sgn = ERROR;
        return -1;
    }
    return 0;
}
int isZero(const struct Number *a)
{
    if (a->sgn == ZERO)
    {
        return 0;
    }
    if (a->sgn == MINUS)
    {
        return -1;
    }
    for (int i = 0; i < KETA; i++)
    {
        if (a->n[i] != 0)
        {
            return -1;
        }
    }
    return 0;
}
void getAbs(const struct Number *a, struct Number *b)
{
    copyNumber(a, b);
    b->sgn = PLUS;
}
void copyNumber(const struct Number *a, struct Number *b)
{
    for (int i = 0; i < KETA; i++)
    {
        b->n[i] = a->n[i];
    }
    b->sgn = a->sgn;
}
void clearByZero(struct Number *a)
{
    for (int i = 0; i < KETA; i++)
    {
        a->n[i] = 0;
    }
    a->sgn = ZERO;
}

void dispNumber(const struct Number *a)
{
    if (a->sgn == PLUS)
    {
        printf("+");
    }
    else if (a->sgn == ZERO)
    {
        printf("0");
        return;
    }
    else if (a->sgn == MINUS)
    {
        printf("-");
    }
    else if (a->sgn == ERROR)
    {
        printf("ERROR");
        return;
    }
    for (int i = KETA - 1; i >= 0; i--)
    {
        printf("\x1b[%dm", numcol[a->n[i]]);
        printf(" %d", a->n[i]);
        printf("\x1b[0m");
    }
}

void setRnd(struct Number *a, int keta)
{
    for (int i = 0; i < keta; i++)
    {
        a->n[i] = (unsigned char)genrand_int32() % 10;
    }
    a->sgn = PLUS;
}