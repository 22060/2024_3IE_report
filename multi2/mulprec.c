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
    b->n[KETA - 1] = 0;
    for (i = 0; i < KETA - 1; i++)
    {
        b->n[i] = a->n[i + 1];
    }
    setSign(b, getSign(a));
    for (i = 0; i < KETA; i++)
    {
        if (b->n[i] != 0)
        {
            break;
        }
        if (i == KETA - 1)
        {
            setSign(b, ZERO);
        }
    }
    return a->n[0];
}
int mulBy10(const struct Number *a, struct Number *b)
{
    int i;
    if (getSign(a) == ZERO)
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
    setSign(b, getSign(a));
    if (a->n[KETA - 1] != 0)
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
        a->n[i] = 0;
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
        printf("\x1b[%dm", numcolors[a->n[i]]);
        printf(" %d", a->n[i]);
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
        a->n[i] = (unsigned char)(genrand_int32() % 10);
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
        a->n[i] = x % 10;
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
        x = x * 10 + a->n[i];
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
            if (a->n[i] > b->n[i])
            {
                return 1;
            }
            else if (a->n[i] < b->n[i])
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
            if (a->n[i] > b->n[i])
            {
                return -1;
            }
            else if (a->n[i] < b->n[i])
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
    static int carry;
    carry = 0;
    struct Number d;
    clearByZero(&d);
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
        c->n[i] = (a->n[i] + b->n[i] + carry);
        carry = (c->n[i]) / 10;
        c->n[i] %= 10;
        // printf("i = %d, a = %d, b = %d, c = %d, carry = %d, add = %d\n", i, a->n[i], b->n[i], c->n[i], carry, a->n[i] + b->n[i]);
        if (i == KETA - 1 && carry > 0)
        {
            return -1;
        }
        // printf("%d\n", c->n[i]);
    }
    if (getInt(c) == 0)
    {
        setSign(c, ZERO);
        // printf("setSign(c, ZERO)\n");
    }
    // printf("c = %d\n", getInt(c));
    return 0;
}

int sub(const struct Number *a, const struct Number *b, struct Number *c)
{
    struct Number d;
    struct Number e;
    int mem = 0;
    int num;
    if (getSign(a) == ZERO)
    {
        copyNumber(b, c);
        setSign(c, getSign(b) * -1);
        return 0;
    }
    else if (getSign(b) == ZERO)
    {
        copyNumber(a, c);
        setSign(c, getSign(a));
        return 0;
    }
    else if (getSign(a) == PLUS && getSign(b) == MINUS)
    {
        getAbs(b, &d);
        num = add(a, &d, c);
        setSign(c, PLUS);
        return num;
    }
    else if (getSign(a) == MINUS && getSign(b) == PLUS)
    {
        getAbs(a, &d);
        num = add(&d, b, c);
        setSign(c, MINUS);
        return num;
    }
    else if (getSign(a) == MINUS && getSign(b) == MINUS)
    {
        getAbs(a, &d);
        getAbs(b, &e);
        num = sub(&e, &d, c);
        return num;
    }
    switch (numComp(a, b))
    {
    case 1:
        for (int i = 0; i < KETA; i++)
        {
            // if (((i % 8) == 0) && (mem == 0) && (i != 0))
            // {
            //     if (a->lli[i / 8] == 0)
            //     {
            //         if (i == 0)
            //             printf("%lld\n", a->lli[i / 8]);
            //         break;
            //     }
            // }
            if (((a->n[i] - b->n[i] - mem) < 0))
            {
                c->n[i] = a->n[i] - b->n[i] - mem + 10;
                mem = 1;
            }
            else
            {
                c->n[i] = a->n[i] - b->n[i] - mem;
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

int simpleMultiple(const struct Number *a, const struct Number *b, struct Number *c)
{
    static struct Number num;
    static struct Number anum;
    static struct Number one;
    static struct Number memo;
    one.n[0] = 1;
    setSign(&one, PLUS);
    // static int i = 0;
    if (getSign(a) == ZERO || getSign(b) == ZERO)
    {
        return 0;
    }
    if (numComp(a, b) == -1)
    {
        simpleMultiple(b, a, c);
    }
    // if (a < b)
    // {
    //     simpleMultiple(b, a, c);
    // }
    getAbs(a, &num);
    getAbs(b, &anum);
    clearByZero(c);
    // printf("a = %d, b = %d\n", *a, *b);
    // while (1)
    // {
    //     if (isZero(&num) == 0)
    //     {
    //         break;
    //     }
    //     // printf("i = %d, num = %d\n", i, num);
    //     add(c, &anum, c);
    //     sub(&num, &one, &num);
    // }
    while (isZero(&num) == -1)
    {
        add(c, &anum, &memo);
        copyNumber(&memo, c);
        sub(&num, &one, &memo);
        copyNumber(&memo, &num);
    }
    // printf("c = %d\n", *c);
    if (getSign(a) != getSign(b))
    {
        setSign(c, MINUS);
    }
    return 0;
}
int multiple(const struct Number *a, const struct Number *b, struct Number *c)
{
    static struct Number d;
    static struct Number e;
    static struct Number f;
    clearByZero(c);
    setSign(c, PLUS);
    clearByZero(&d);
    setSign(&d, PLUS);
    clearByZero(&e);
    setSign(&e, PLUS);
    for (int i = 0; i < KETA; i++)
    {
        clearByZero(&d);
        setSign(&d, PLUS);
        clearByZero(&e);
        setSign(&e, PLUS);
        clearByZero(&f);
        setSign(&f, PLUS);
        for (int j = 0; j < b->n[i]; j++)
        {
            add(&f, a, &d);
            // printf("f = %d, a = %d, d = %d\n", getInt(&f), getInt(a), getInt(&d));
            // printf("f + a = %d\n", getInt(&f) + getInt(a));
            copyNumber(&d, &f);
            // printf("d = %d, e = %d\n", getInt(&d), getInt(&e));
            // printf("d = %d, e = %d\n", getInt(&d), getInt(&e));
        }
        for (int t = 0; t < i; t++)
        {
            mulBy10(&d, &e);
            copyNumber(&e, &d);
        }
        clearByZero(&f);
        add(c, &d, &f);
        copyNumber(&f, c);
        // printf("i = %d, d = %d,c = %d\n", i, getInt(&d), getInt(c));
        // printf("i = %d, c = %d,j = %d\n", i, getInt(c), b->n[i]);
    }
    return 0;
}

int simpleDivide(const struct Number *a, const struct Number *b, struct Number *c)
{
    struct Number num;
    struct Number one;
    clearByZero(&one);
    setInt(&one, 1);
    clearByZero(c);
    clearByZero(&num);
    copyNumber(a, &num);
    getAbs(a, &num);
    static int n;
    n = 0;
    // printf("a = %d, b = %d\n", getInt(a), getInt(b));
    if (getSign(a) == ZERO || getSign(b) == ZERO)
    {
        clearByZero(c);
        return 0;
    }
    else if (getSign(b) == PLUS)
    {
        while (numComp(b, &num) != 1 && num.sgn != MINUS)

        {
            // printf("num = %d, b = %d,", getInt(&num), getInt(b));
            sub(&num, b, &num);
            add(c, &one, c);
            // printf("c = %d\n", getInt(c));
        }
    }
    else if (getSign(b) == MINUS)
    {
        while ((numComp(b, &num) != 1) && (num.sgn != MINUS))
        {
            // printf("num = %d, b = %d,", getInt(&num), getInt(b));
            add(&num, b, &num);
            add(c, &one, c);
            // printf("c = %d\n", getInt(c));
        }
        sub(c, &one, c);
    }
    // setInt(c, n);
    // setSign(c, PLUS);
    return num.n[0];
}
#endif