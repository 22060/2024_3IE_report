#ifndef MULPREC.C
#define EXTERN
#include "mulprec.h"
#include <stdio.h>
int numcolors[10] = {0, 31, 32, 33, 34, 91, 92, 93, 94, 95};
int divBy10(const struct Number *a, struct Number *b)
{
    int i;
    if (getSign(b) == ZERO)
    {
        clearByZero(b);
        return 0;
    }
    b->n[KETA - 1].value = 0;
    for (i = 0; i < KETA - 1; i++)
    {
        b->n[i] = a->n[i + 1];
    }
    setSign(b, getSign(a));
#if KETA >= 16
    int flag = 0;
    for (i = 0; i < KETA / 16; i++)
    {
        if (b->lli[i] != 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        setSign(b, ZERO);
    }
#else
    if (b->lli[0] == 0)
    {
        setSign(b, ZERO);
    }
#endif

    return a->n[0].value;
}
int mulBy10(const struct Number *a, struct Number *b)
{
    int i;
    if (getSign(a) == ZERO)
    {
        clearByZero(b);
        return 0;
    }
    b->n[0].value = 0;
    for (i = 0; i < KETA - 1; i++)
    {
        b->n[i + 1] = a->n[i];
    }
    b->n[KETA - 1].value = 0;
    setSign(b, getSign(a));
    if (a->n[KETA - 1].value != 0)
    {
        return -1;
    }
    return 0;
}
int isZero(const struct Number *a)
{
    if (getSign(a) == ZERO)
    {
        return 0;
    }
    if (getSign(a) == MINUS)
    {
        return -1;
    }
    for (int i = 0; i < KETA; i++)
    {
        if (a->n[i].value != 0)
        {
            return -1;
        }
    }
    return 0;
}
void getAbs(const struct Number *a, struct Number *b)
{
    copyNumber(a, b);
    setSign(b, PLUS);
}
void copyNumber(const struct Number *a, struct Number *b)
{
    for (int i = 0; i < KETA; i++)
    {
        b->n[i] = a->n[i];
    }
    setSign(b, getSign(a));
}
void clearByZero(struct Number *a)
{
    for (int i = 0; i < KETA; i++)
    {
        a->n[i].value = 0;
    }
    setSign(a, ZERO);
}

void dispNumber(const struct Number *a)
{
    if (getSign(a) == PLUS)
    {
        printf("+");
    }
    else if (getSign(a) == ZERO)
    {
        printf("0");
        return;
    }
    else if (getSign(a) == MINUS)
    {
        printf("-");
    }
    else if (getSign(a) == ERROR)
    {
        printf("ERROR");
        return;
    }
    for (int i = KETA - 1; i >= 0; i--)
    {
        printf("\x1b[%dm", numcolors[a->n[i].value]);
        printf(" %d", a->n[i].value);
        printf("\x1b[0m");
    }
}

void setRnd(struct Number *a, int keta)
{
    if(keta > KETA){
        keta = KETA;
    }
    for (int i = 0; i < keta; i++)
    {
        a->n[i].value = (unsigned char)genrand_int32() % 10;
    }
    setSign(a, PLUS);
}

int setInt(struct Number *a, int x)
{
    // if (x == 0)
    // {
    //     clearByZero(a);
    //     return 0;
    // }
    clearByZero(a);
    if (x > 0)
    {
        setSign(a, PLUS);
    }
    else
    {
        setSign(a, MINUS);
        x = -1 * x;
    }
    int i = 0;
    while (x > 0)
    {
        a->n[i].value = x % 10;
        x /= 10;
        i++;
        if(i >= KETA){
            return -1;
        }
    }
    return 0;
}

int getInt(const struct Number *a)
{
    int x = 0;
    for (int i = KETA - 1; i >= 0; i--)
    {
        x = x * 10 + a->n[i].value;
    }
    if (getSign(a) == MINUS)
    {
        x = -1 * x;
    }
    return x;
}

int setSign(struct Number *a, int s)
{
    switch (s)
    {
    case PLUS:
        a->sgn = PLUS;
        break;
    case ZERO:
        a->sgn = ZERO;
        break;
    case MINUS:
        a->sgn = MINUS;
        break;
    default:
        return -1;
    }
    return 0;
}

int getSign(const struct Number *a)
{
    return a->sgn;
}

int numComp(const struct Number *a, const struct Number *b)
{
    // if(getSign(a) == getSign(b) == ZERO){
    //     return 0;
    // }else
    if (getSign(a) == PLUS && getSign(b) == MINUS)
    {
        return 1;
    }
    else if (getSign(a) == MINUS && getSign(b) == PLUS)
    {
        return -1;
    }
    else if(getSign(a) == PLUS && getSign(b) == PLUS){
        for(int i = KETA / 16; i > 0 ; i--){
            if(a->lli[i] != b->lli[i]){
                printf("a->lli[%d] = %lld, b->lli[%d] = %lld\n", i, a->lli[i], i, b->lli[i]);
                for(int j = 16; j > 0 ; j--){
                    if(a->n[16 + j].value > b->n[16 + j].value){
                        return -1;
                    }else if(a->n[16 + j].value < b->n[16 + j].value){
                        return 1;
                    }
                }
            }
        }
    }else if(getSign(a) == MINUS && getSign(b) == MINUS){
        for(int i = KETA / 16; i > 0 ; i--){
                for(int j = 16; j > 0 ; j--){
                    if(a->n[16 + j].value > b->n[16 + j].value){
                        return 1;
                    }else if(a->n[16 + j].value < b->n[16 + j].value){
                        return -1;
                    }
                }
        }
        return 0;
    }


}
#endif