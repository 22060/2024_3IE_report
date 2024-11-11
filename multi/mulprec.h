
#ifndef MULPREC_H
#define MULPREC_H
#define KETA 10000
#define PLUS 1
#define ZERO 0
#define MINUS -1
#define ERROR -2
struct Number
{
    union
    {
        char n[KETA];
#if KETA >= 8
        long long int lli[KETA / 8];
#else
        long long int lli[1];
#endif
    };
    int sgn;
};

void clearByZero(struct Number *a);
void dispNumber(const struct Number *a);
void setRnd(struct Number *a, int keta);
void copyNumber(const struct Number *a, struct Number *b);
void getAbs(const struct Number *a, struct Number *b);
int isZero(const struct Number *a);
int mulBy10(const struct Number *a, struct Number *b);
int divBy10(const struct Number *a, struct Number *b);
#endif