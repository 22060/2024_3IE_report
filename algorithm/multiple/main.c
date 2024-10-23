#include <stdio.h>

int main(void){
    float x = -123456; // 0xfffe1dc0
    unsigned char *p;

    p = (unsigned char *)&x;
    printf("%02x %02x %02x %02x\n", *p, *(p+1), *(p+2), *(p+3));
}