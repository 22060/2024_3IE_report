#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 1000
int comparison(int n1,int n2,int n3);
void Quicksort(int *array, int left, int right);
void swap(int *a,int *b);

int main(void){
    int array[NUM] = {0};
    srand((unsigned)time(NULL));
    for (int i = 0; i < NUM; i++)
    {
        array[i] = rand() % 1000;
    }
    printf("Before sorting: \n");
    for (int i = 0; i < NUM; i++)
    {
        printf("%d ",array[i]);
    }
    Quicksort(array,0,NUM-1);
    printf("\nAfter sorting: \n");
    for (int i = 0; i < NUM; i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
    return 0;

}
void Quicksort(int *array, int left, int right){
    if(left >= right)return;
    int povit = comparison(array[left],array[right],array[(left+right)/2]);
    int l = left;
    int r = right;
    printf("\npovit = %d\n",povit);
    while (1)
    {
        while(array[l] < povit)l++;
        while(array[r] > povit)r--;
        if(l >= r)break;
        swap(&array[l],&array[r]);
        l++;
        r--;
    }
    
    Quicksort(array,left,l-1);
    Quicksort(array,r+1,right);
}

int comparison(int n1,int n2,int n3){
    if (n1 < n2 && n2 < n3) {
        return n2;
    } else if (n2 < n1) {
        return n1;
    } else {
        return n3;
    }
}

void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}