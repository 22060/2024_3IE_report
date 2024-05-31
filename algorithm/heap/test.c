#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#define HEAPMAX 20

struct heap_template
{
    int box[HEAPMAX];
    int size;
};
typedef struct heap_template heap;

void InitHeap(heap *h);
void InsertHeap(heap *h, int x);
int TopHeap(heap *h);
void DeleteHeap(heap *h);

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// ヒープを初期化
void InitHeap(heap *h)
{
    for (int i = 0; i < HEAPMAX; i++)
    {
        h->box[i] = 0;
    }
    h->size = 0;
}

// 挿入
void InsertHeap(heap *h, int x)
{
    h->box[h->size] = x;
    int a = h->size;
    int adjustment = h->size - 1;
    int blank = 0;
    h->size++;

    while (h->box[(adjustment - 1) / 2] < h->box[adjustment] && adjustment != 0)
    {
        swap(&h->box[(adjustment - 1) / 2], &h->box[adjustment]);
        adjustment = (adjustment - 1) / 2;
    }
}

int TopHeap(heap *h)
{
    return h->box[0];
}

void DeleteHeap(heap *h)

{
    int blank = 0;
    int left = blank * 2 + 1;
    int right = blank * 2 + 2;
    int now = 0;
    h->size--;

    // 332910
    // 622111
    h->box[0] = h->box[h->size];
    h->box[h->size] = 0;
    for (int i = 0; i < log2(HEAPMAX); i++)
    {

        if (h->box[left] > h->box[blank])
        {
            // 変数の入れ替え開始
            int tmp = h->box[blank];
            h->box[blank] = h->box[left];
            h->box[left] = tmp;
            // 変数の入れ替え終り
            blank = left; // 入れ替えした後に今操作している変数がどこにあるかのindexを代入(leftにいったのでleft indexを代入)
            left = blank * 2 + 1;
            right = blank * 2 + 2;
        }
        else if (h->box[right] > h->box[blank])
        {
            // 変数の入れ替え開始
            int tmp = h->box[blank];
            h->box[blank] = h->box[right];
            h->box[right] = tmp;
            // 変数の入れ替え終り
            blank = right; // 入れ替えした後に今操作している変数がどこにあるかのindexを代入(rightにいったのでright indexを代入)
            left = blank * 2 + 1;
            right = blank * 2 + 2;
        }
    }
}

int main(void)
{
    srand(time(NULL));
    heap h;
    int random[HEAPMAX];
    int x;
    InitHeap(&h);

    // for (int i = 0; i < HEAPMAX; i++)
    // {
    //     x = rand() % 100 + 1;
    //     random[i] = x;
    //     printf("%d ", random[i]);
    //     InsertHeap(&h, x);
    // }
    // printf("\n");

    for (int i = 0; i < 10; i++)
    {
        x = rand() % 100 + 1;
        InsertHeap(&h, x);
        printf("insert:");
        printf("heap:");
        int now = 0;
        while (h.box[now] != 0)
        {
            printf("%d ", h.box[now]);
            now++;
        }
        printf("\n");
    }
    for (int i = 0; i < 10; i++)
    {
        DeleteHeap(&h);
        printf("delete:");
        int now = 0;
        while (h.box[now] != 0)
        {
            printf("%d ", h.box[now]);
            now++;
        }
        printf("\n");
    }
    return 0;
}
