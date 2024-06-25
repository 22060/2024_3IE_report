#include <stdio.h>

#define DATA 10

void insert(int * a,int n,int e);

void insertsort(int *a);

int main(void){
    int a[DATA];
    for (int i = 0; i < DATA; i++)
    {
        a[i] = DATA - i;
    }
    insertsort(a);
    return 0;
}

void insertsort(int *a){
    int t = 0;
    for (int i = 1; i < DATA; i++)
    {
        t = i - 1;
        while (a[t] > a[i]){
            t--;
            if(t == -1){
                break;
            }
        }
        insert(a,i,t+1);
        for (int i = 0; i < DATA; i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
        
        
    }
    
}

void insert(int * a,int n,int e){
    int tmp = a[n];
    for (int i = n; i > e; i--)
    {
        a[i] = a[i-1];
    }
    a[e] = tmp;
}