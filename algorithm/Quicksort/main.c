/*211 古城隆人
課題内容:
クイックソートを実装する。
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

int NUM = 100;

long count[6];

struct args
{
    int debug;
    int changecount;
    int func;
    int isprintf;
};

typedef struct args args;

args arg;

int comparison(int n1, int n2, int n3, int n1_index, int n2_index, int n3_index);
void Quicksort(int *array, int left, int right);
void swap(int *a, int *b);
void bubblesort(int *array, int num);
void margesort(int *array, int left, int right);
void shellsort(int *array, int num);
void heapsort(int *array, int num);
void selectionsort(int *array, int num);
void (*funcs[])(int *, int) = {selectionsort, heapsort, shellsort, bubblesort};

void argselection(int argc, char *argv[], args *arg);

int main(int argc, char *argv[])
{
    for (int i = 0; i < 6; i++)
    {
        count[i] = 0;
    }

    argselection(argc, argv, &arg);
    int array[NUM];
    int array2[NUM];
    for (int i = 0; i < NUM; i++)
    {
        array[i] = 0;
        array2[i] = 0;
    }

    for (int i = 0; i < arg.debug; i++)
    {
        srand((unsigned)time(NULL));
        for (int i = 0; i < NUM; i++)
        {
            array[i] = rand() % 500;
        }
        if (arg.isprintf)
        {
            printf("Before sorting: \n");
            for (int i = 0; i < NUM; i++)
            {
                printf("%d ", array[i]);
            }
            printf("\n");
        }
        if (arg.debug >= 2)
        {
            for (int i = 0; i < 4; i++)
            {
                memcpy(array2, array, sizeof(int) * NUM);
                funcs[i](array2, NUM);
            }

            memcpy(array2, array, sizeof(int) * NUM);
            if (arg.isprintf)
            {
                printf("margesort\n [ ");
                for (int i = 0; i < NUM; i++)
                {
                    printf("%d ", array2[i]);
                }
            }
            margesort(array2, 0, NUM - 1);
            if (arg.isprintf)
            {
                printf("] ==> [ ");
                for (int i = 0; i < NUM; i++)
                {
                    printf("%d ", array2[i]);
                }
                printf("]\n");
            }
        }
        memcpy(array2, array, sizeof(int) * NUM);
        Quicksort(array2, 0, NUM - 1);
        if (arg.isprintf)
        {
            printf("\nAfter sorting: \n");
            for (int i = 0; i < NUM; i++)
            {
                printf("%d ", array2[i]);
            }
        }
    }
    printf("\n");
    if (arg.debug >= 2)
    {
        printf("選択ソートの平均比較回数 %ld\n", count[0] / arg.debug);
        printf("ヒープソートの平均比較回数 %ld\n", count[1] / arg.debug);
        printf("シェルソートの平均比較回数 %ld\n", count[2] / arg.debug);
        printf("バブルソートの平均比較回数 %ld\n", count[3] / arg.debug);
        printf("マージソートの平均比較回数 %ld\n", count[4] / arg.debug);
        printf("クイックソートの平均比較回数 %ld\n", count[5] / arg.debug);
    }
    // while(1);
    return 0;
}

void argselection(int argc, char *argv[], args *arg)
{
    arg->debug = 1;
    arg->changecount = 0;
    arg->func = 0;
    arg->isprintf = 1;
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-d") == 0)
        {
            arg->debug = (argv[i + 1] == NULL) ? 1 : atoi(argv[i + 1]);
            i++;
        }
        else if (strcmp(argv[i], "-m") == 0)
        {
            arg->changecount = (argv[i + 1] == NULL) ? 10 : atoi(argv[i + 1]);
            i++;
            arg->func = (argv[i + 1] == NULL) ? 0 : atoi(argv[i + 1]);
            i++;
        }
        else if (strcmp(argv[i], "-p") == 0)
        {
            arg->isprintf = 0;
        }
    }
    // printf("debug = %d\nmode = %d\nisprintf = %d\n",arg->debug,arg->mode,arg->isprintf);
}

void selectionsort(int *array, int num)
{
    if (arg.isprintf)
    {
        printf("selectionsort\n [ ");
        for (int i = 0; i < num; i++)
        {
            printf("%d ", array[i]);
        }
        printf("] ==> [ ");
    }
    for (int i = 0; i < num; i++)
    {
        int min = i;
        for (int j = i + 1; j < num; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
            count[0]++;
        }
        swap(&array[i], &array[min]);
    }
    if (arg.isprintf)
    {
        for (int i = 0; i < num; i++)
        {
            printf("%d ", array[i]);
        }
        printf("]\n");
    }
}

void heapsort(int *array, int num)
{
    if (arg.isprintf)
    {
        printf("heapsort\n [ ");
        for (int i = 0; i < num; i++)
        {
            printf("%d ", array[i]);
        }
        printf("] ==> [ ");
    }
    for (int i = num / 2 - 1; i >= 0; i--)
    {
        int parent = i;
        int child = 2 * i + 1;
        while (child < num)
        {
            if (child + 1 < num && array[child] < array[child + 1])
            {
                child++;
            }
            if (array[parent] < array[child])
            {
                swap(&array[parent], &array[child]);
                parent = child;
                child = 2 * parent + 1;
            }
            else
            {
                break;
            }
            count[1]++;
        }
    }
    for (int i = num - 1; i > 0; i--)
    {
        swap(&array[0], &array[i]);
        int parent = 0;
        int child = 1;
        while (child < i)
        {
            if (child + 1 < i && array[child] < array[child + 1])
            {
                child++;
            }
            if (array[parent] < array[child])
            {
                swap(&array[parent], &array[child]);
                parent = child;
                child = 2 * parent + 1;
            }
            else
            {
                break;
            }
            count[1]++;
        }
    }
    if (arg.isprintf)
    {
        for (int i = 0; i < num; i++)
        {
            printf("%d ", array[i]);
        }
        printf("]\n");
    }
}

void shellsort(int *array, int num)
{
    if (arg.isprintf)
    {
        printf("shellsort\n [ ");
        for (int i = 0; i < num; i++)
        {
            printf("%d ", array[i]);
        }
        printf("] ==> [ ");
    }
    for (int h = num / 2; h > 0; h /= 2)
    {
        for (int i = h; i < num; i++)
        {
            int tmp = array[i];
            int j = i;
            for (; j >= h && array[j - h] > tmp; j -= h)
            {
                array[j] = array[j - h];
                count[2]++;
            }
            array[j] = tmp;
        }
    }
    if (arg.isprintf)
    {
        for (int i = 0; i < num; i++)
        {
            printf("%d ", array[i]);
        }
        printf("]\n");
    }
}

void margesort(int *array, int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    margesort(array, left, mid);
    margesort(array, mid + 1, right);
    int *tmp = (int *)malloc(sizeof(int) * (right - left + 1));
    int l = left;
    int r = mid + 1;
    int t = 0;
    while (l <= mid && r <= right)
    {
        if (array[l] < array[r])
        {
            tmp[t++] = array[l++];
        }
        else
        {
            tmp[t++] = array[r++];
        }
        count[4]++;
    }
    while (l <= mid)
    {
        tmp[t++] = array[l++];
    }
    while (r <= right)
    {
        tmp[t++] = array[r++];
    }
    for (int i = 0; i < t; i++)
    {
        array[left + i] = tmp[i];
    }
    free(tmp);
}

void bubblesort(int *array, int num)
{
    if (arg.isprintf)
    {
        printf("bubblesort\n [ ");
        for (int i = 0; i < num; i++)
        {
            printf("%d ", array[i]);
        }
        printf("] ==> [ ");
    }
    for (int i = 0; i < num; i++)
    {
        for (int j = num - 1; j > i; j--)
        {
            if (array[j] < array[j - 1])
            {
                swap(&array[j], &array[j - 1]);
            }
            count[3]++;
        }
    }
    if (arg.isprintf)
    {
        for (int i = 0; i < num; i++)
        {
            printf("%d ", array[i]);
        }
        printf("]\n");
    }
}

void Quicksort(int *array, int left, int right)
{
    if (left >= right)
        return;
    if (right - left <= arg.changecount)
    {
        if (arg.func == 4)
        {
            margesort(array, left, right);
            return;
        }
        funcs[(arg.func > 3 ? 0 : arg.func)](array + left, right - left + 1);
        return;
    }
    int povit = comparison(array[left], array[right], array[(left + right) / 2], left, right, (left + right) / 2);
    int l = left;
    int r = right;
    if (arg.isprintf)
    {

        printf("\npovit = %d\n[ ", array[povit]);

        for (int i = left; i < right + 1; i++)
        {
            printf("%d ", array[i]);
        }
    }
    while (1)
    {
        while (array[l] < array[povit])
        {
            l++;
            count[5]++;
        }
        while (array[r] > array[povit])
        {
            r--;
            count[5]++;
        }
        if (l >= r)
            break;
        swap(&array[l], &array[r]);
        l++;
        r--;
    }
    if (arg.isprintf)
    {
        printf("] ==> [ ");
        for (int i = left; i < l + ((l - r) == 0) ? 1 : 0; i++)
        {
            printf("%d ", array[i]);
        }
        printf("] [ ");
        for (int i = r + 1; i < right + 1; i++)
        {
            printf("%d ", array[i]);
        }
        printf("]\n");
    }

    Quicksort(array, left, l - 1);
    Quicksort(array, r + 1, right);
}

int comparison(int n1, int n2, int n3, int n1_index, int n2_index, int n3_index)
{
    if (n1 < n2 && n2 < n3)
    {
        return n2_index;
    }
    else if (n2 < n1 && n1 < n3)
    {
        return n1_index;
    }
    else
    {
        return n3_index;
    }
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}