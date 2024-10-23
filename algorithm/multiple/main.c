#include <stdio.h>

int main(void){
    int x = -123456; // 0xfffe1dc0
    float y = -12.3456; // 0xc1458794
    unsigned char *p;

    p = (unsigned char *)&y;
    printf("%02x %02x %02x %02x\n", *(p), *(p+1), *(p+2), *(p+3));
    for(int i = 0; i < 32; i++){
        // printf("%d ",*(p+3 - (i/8)));
        printf("%d", *(p+3 - (i/8))>>(7 - i%8) & 1);
        printf("%c", i%8 == 7 ? ' ' : '\0');
    }
}