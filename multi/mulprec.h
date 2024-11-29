
#ifndef MULPREC_H
#define MULPREC_H
#define KETA 10
#define PLUS 1
#define ZERO 0
#define MINUS -1
#define ERROR -2

typedef struct {
    unsigned int value : 4;
} half_char;
struct Number
{
    union
    {
        half_char n[KETA];
#if KETA >= 16
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
int setInt(struct Number *a, int x);
int getInt(const struct Number *a);
int setSign(struct Number *a, int s);
int getSign(const struct Number *a);
/*
a > b : 1
a = b : 0
a < b : -1
*/
int numComp(const struct Number *a, const struct Number *b);

int add(const struct Number *a, const struct Number *b, struct Number *c);
int sub(const struct Number *a, const struct Number *b, struct Number *c);
int simpleMultiple(const struct Number *a, const struct Number *b, struct Number *c);
int multiple(const struct Number *a, const struct Number *b, struct Number *c);
#endif