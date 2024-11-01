#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[50];
    int karasa;
    int ryou;
}Curry;
void printcurry(Curry *curry);
int main(void){
    Curry c,d;
    strcpy(c.name,"karai curry");
    c.karasa = 5;
    c.ryou = 200;
    printcurry(&c);
    strcpy(d.name,"amai curry");
    d.karasa = 1;
    d.ryou = 100;
    printcurry(&d);
}

void printcurry(Curry *curry){
    printf("curry name :%s\n",curry->name);
    printf("karasa :%d\n",curry->karasa);
    printf("ryou :%d\n",curry->ryou);
}