#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define HEAPMAX 1000

typedef struct
{
    int box[HEAPMAX];
    int size;
} Heap;

void InitHeap(Heap *h);
void InsertHeap(Heap *h, int x);
int TopHeap(Heap *h);
int DeleteHeap(Heap *h);
void PrintHeap(Heap *h);
void swap(int *a, int *b);

int main()
{
    Heap h;
    InitHeap(&h);
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        InsertHeap(&h, rand() % 100);
        printf("insert:");
        PrintHeap(&h);
    }
    for (int i = 0; i < 10; i++)
    {
        DeleteHeap(&h);
        printf("delete:");
        PrintHeap(&h);
    }
    return 0;
}
void InitHeap(Heap *h)
{
    h->size = 0;
    for (int i = 0; i < HEAPMAX; i++)
    {
        h->box[i] = 0;
    }
}
void InsertHeap(Heap *h, int x)
{
    h->size++;
    int now = h->size - 1;
    h->box[now] = x;

    while (h->box[(now - 1) / 2] < h->box[now] && now != 0)
    {
        swap(&h->box[(now - 1) / 2],&h->box[now]);
        now = (now - 1) / 2;
    }
}
int TopHeap(Heap *h)
{
    return h->box[0];
}
int DeleteHeap(Heap *h)
{
    h->box[0] = 0;
    h->box[0] = h->box[h->size - 1];
    h->box[h->size - 1] = 0;
    h->size--;
    int now = 0;
    while (h->box[now*2+1] > h->box[now] || h->box[now*2+2] > h->box[now])
    {
        if(h->box[now*2+1] > h->box[now]){
            swap(&h->box[now*2+1],&h->box[now]);
            now = now*2+1;
        }
        else if(h->box[now*2+2] > h->box[now]){
            swap(&h->box[now*2+2],&h->box[now]);
            now = now*2+2;
        }
        else break;
    }
    return h->box[0];
}
void PrintHeap(Heap *h)
{
    printf("heap: ");
    int now = 0;
    while (h->box[now] != 0)
    {
        printf("%d ", h->box[now]);
        now++;
    }

    printf("\n");
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}