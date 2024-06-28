#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 500
int comparison(int n1,int n2,int n3,int n1_index,int n2_index,int n3_index);
void Quicksort(int *array, int left, int right);
void swap(int *a,int *b);
struct node
{
    int value;
    int next;
    int prev;
};


int main(void){
    int array[NUM] = {0};
    srand((unsigned)time(NULL));
    for (int i = 0; i < NUM; i++)
    {
        array[i] = rand() % 500;
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
    int povit = comparison(array[left],array[right],array[(left+right)/2],left,right,(left+right)/2);
    int l = left;
    int r = right;
    printf("\npovit = %d\n[ ",array[povit]);

    for (int i = left; i < right+1; i++)
    {
        printf("%d ",array[i]);
    }
    while (1)
    {
        while(array[l] < array[povit])l++;
        while(array[r] > array[povit])r--;
        if(l >= r)break;
        swap(&array[l],&array[r]);
        l++;
        r--;
    }
    printf("] ==> [ ");
    for(int i = left; i < l+((l-r)==0)?1:0;i++){
        printf("%d ",array[i]);
    }
    printf("] [ ");
    for(int i = r+1; i < right+1;i++){
        printf("%d ",array[i]);
    }
    printf("]\n");
    
    
    Quicksort(array,left,l-1);
    Quicksort(array,r+1,right);
}

int comparison(int n1,int n2,int n3,int n1_index,int n2_index,int n3_index){
    if (n1 < n2 && n2 < n3) {
        return n2_index;
    } else if (n2 < n1 && n1 < n3) {
        return n1_index;
    } else {
        return n3_index;
    }
}

void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}