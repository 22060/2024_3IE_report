#ifndef MULPREC_C
#define MULPREC_C
#include "mulprec.h"
#include <stdio.h>
extern unsigned long genrand_int32();
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
    if (keta > KETA)
    {
        keta = KETA;
    }
    for (int i = 0; i < keta; i++)
    {
        a->n[i].value = (unsigned char)(genrand_int32() % 10);
    }
    setSign(a, PLUS);
}

int setInt(struct Number *a, int x)
{
    clearByZero(a);
    if (x == 0)
    {
        return 0;
    }
    else if (x > 0)
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
        if (i >= KETA)
        {
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
    if (getSign(a) == ZERO)
    {
        if (getSign(b) == PLUS)
        {
            return -1;
        }
        else if (getSign(b) == MINUS)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (getSign(b) == ZERO)
    {
        if (getSign(a) == PLUS)
        {
            return 1;
        }
        else if (getSign(a) == MINUS)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
    else if (getSign(a) == PLUS && getSign(b) == MINUS)
    {
        return 1;
    }
    else if (getSign(a) == MINUS && getSign(b) == PLUS)
    {
        return -1;
    }
    else if (getSign(a) == PLUS && getSign(b) == PLUS)
    {
        for (int i = KETA - 1; i >= 0; i--)
        {
            if (a->n[i].value > b->n[i].value)
            {
                return 1;
            }
            else if (a->n[i].value < b->n[i].value)
            {
                return -1;
            }
        }
        return 0;
    }
    else if (getSign(a) == MINUS && getSign(b) == MINUS)
    {
        for (int i = KETA - 1; i >= 0; i--)
        {
            if (a->n[i].value > b->n[i].value)
            {
                return -1;
            }
            else if (a->n[i].value < b->n[i].value)
            {
                return 1;
            }
        }
        return 0;
    }
    return 0;
}

int add(const struct Number *a, const struct Number *b, struct Number *c)
{
    int carry = 0;
    struct Number d;
    if (getSign(a) == ZERO)
    {
        copyNumber(b, c);
        return 0;
    }
    else if (getSign(b) == ZERO)
    {
        copyNumber(a, c);
        return 0;
    }
    else if (getSign(a) == PLUS && getSign(b) == MINUS)
    {
        getAbs(b, &d);
        sub(a, &d, c);
        return 0;
    }
    else if (getSign(b) == PLUS && getSign(a) == MINUS)
    {
        getAbs(a, &d);
        sub(b, &d, c);
        return 0;
    }
    else if (getSign(a) == MINUS && getSign(b) == MINUS)
    {
        setSign(c, MINUS);
    }
    else
    { // PLUS, PLUS
        setSign(c, PLUS);
    }

    for (int i = 0; i < KETA; i++)
    {

        // if (((i % 8) == 0) && (carry == 0) && (i != 0))
        // {
        //     if (a->lli[i / 8] == 0)
        //     {
        //         if (i == 0)
        //             printf("%lld\n", a->lli[i / 8]);
        //         break;
        //     }
        // }
        // printf("i = %d, a = %d, b = %d, c = %d, carry = %d, add = %d\n", i, a->n[i].value, b->n[i].value, c->n[i].value, carry, a->n[i].value + b->n[i].value);
        c->n[i].value = (a->n[i].value + b->n[i].value + carry) % 10;
        carry = (a->n[i].value + b->n[i].value + carry) / 10;
        // printf("i = %d, a = %d, b = %d, c = %d, carry = %d, add = %d\n", i, a->n[i].value, b->n[i].value, c->n[i].value, carry, a->n[i].value + b->n[i].value);
        if (i == KETA - 1 && carry > 0)
        {
            return -1;
        }
        // printf("%d\n", c->n[i].value);
    }
    if (getInt(c) == 0)
    {
        setSign(c, ZERO);
        printf("setSign(c, ZERO)\n");
    }
    return 0;
}

int sub(const struct Number *a, const struct Number *b, struct Number *c)
{
    struct Number d;
    struct Number e;
    int mem = 0;
    if(getSign(a) == ZERO){
        copyNumber(b, c);
        setSign(c, getSign(b) * -1);
        return 0;
    }else if(getSign(b) == ZERO){
        copyNumber(a, c);
        setSign(c, getSign(a));
        return 0;
    }else if(getSign(a) == PLUS && getSign(b) == MINUS){
        getAbs(b, &d);
        add(a, &d, c);
        setSign(c, PLUS);
        return 0;
    }else if(getSign(a) == MINUS && getSign(b) == PLUS){
        getAbs(a, &d);
        add(&d, b, c);
        setSign(c, MINUS);
        return 0;
    }else if(getSign(a) == MINUS && getSign(b) == MINUS){
        getAbs(a, &d);
        getAbs(b, &e);
        sub(&e, &d, c);
        return 0;
    }
    switch (numComp(a, b))
    {
    case 1:
        for (int i = 0; i < KETA; i++)
        {
            if (((i % 8) == 0) && (mem == 0) && (i != 0))
            {
                if (a->lli[i / 8] == 0)
                {
                    if (i == 0)
                        printf("%lld\n", a->lli[i / 8]);
                    break;
                }
            }
            if (((a->n[i].value - b->n[i].value - mem) < 0))
            {
                c->n[i].value = a->n[i].value - b->n[i].value - mem + 10;
                mem = 1;
            }
            else
            {
                c->n[i].value = a->n[i].value - b->n[i].value - mem;
                mem = 0;
            }
        }
        setSign(c, PLUS);
        break;
    case 0:
        clearByZero(c);
        return 0;
    case -1:
        sub(b, a, c);
        setSign(c, MINUS);
        break;
    }
    return 0;
}
#endif