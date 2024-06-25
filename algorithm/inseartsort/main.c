

#define DATA 10

void insert(int * a,int n,int n2);

void insertsort(int a[], int n);

int main(void){
    int a[] = {1,3,5,7,9,2,4,6,8,10};
    insert(a,5,0);

}

void insert(int * a,int n,int n2){
    for (int i = DATA; i > n; i--)
    {
        a[i] = a[i-1];
    }
    a[n] = n2;
}