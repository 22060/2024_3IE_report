#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define DATA 1000

void insert(int *a, int n, int e);

void insertsort(int *a, long *count);

int main(void)
{
    long count = 0;
    int a[DATA];
    for (int i = 0; i < 10; i++)
    {
        int stime = time(NULL);
        srand(stime);
        for (int i = 0; i < DATA; i++)
        {
            a[i] = rand() % DATA * 10;
        }
        insertsort(a, &count);
        printf("かかった時間 %d s\n", (int)time(NULL) - stime);
        printf("比較回数 %ld\n", count);
        printf("オーダー %f[DATA^count]\n", log2((double)count) / log2((double)DATA));
        count = 0;
    }
    

    return 0;
}

void insertsort(int *a, long *count)
{
    int t = 0;
    for (int i = 1; i < DATA; i++)
    {
        t = i - 1;
        (*count)++;
        while (a[t] > a[i])
        {
            (*count)++;
            t--;
            if (t == -1)
            {
                break;
            }
        }
        insert(a, i, t + 1);
    }
}

void insert(int *a, int n, int e)
{
    int tmp = a[n];
    for (int i = n; i > e; i--)
    {
        a[i] = a[i - 1];
    }
    a[e] = tmp;
}