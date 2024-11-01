#include <stdio.h>


unsigned long long int kansuu(double c){
     long int a = 12345;
    static double d = 1.234;
    printf("pointer a: %p\n", (void *)&a);
    printf("pointer c: %p\n", (void *)&c);
    printf("pointer d: %p\n", (void *)&d);
    return (unsigned long long int)&a;
}
int main(){
    double b = 0;
    printf("pointer b: %p\n", (void *)&b);
    unsigned long long int ptr = kansuu(b);
    printf("ptr cpy d: %p\n", (void *)ptr);
    printf("d: %d\n", *(int *)ptr);

    return 0;
}