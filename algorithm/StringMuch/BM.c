#include <stdio.h>
#define STR_NUM 2500
int main(int argc, char *argv[])
{
    //変数の宣言
    FILE *fp;
    char str[STR_NUM];
    int t = 0;
    //変数の初期化
    char str2[100] = "doremifasorashido";
    for (int i = 0; i < STR_NUM; i++)
    {
        str[i] = 0;
    }

    if (argc == 2)
    {
        fp = fopen(argv[1], "r");
        if (fp == NULL)
        {
            printf("file open error\n");
            return 1;
        }
        while (fgets(str, STR_NUM, fp) != NULL)
        {
            printf("%s", str);
        }
    }
    else
    {
        fp = fopen("example.txt", "r");
        if (fp == NULL)
        {
            printf("file open error\n");
            return 1;
        }
        while (fgets(str, STR_NUM, fp) != NULL)
        {
            // printf("%s", str);
        }
    }
    //スキップテーブル作成
    int skip[256];
    int size = 0;
    while(str2[size] != 0)
    {
        size++;
    }
    for (int i = 0; i < 256; i++)
    {
        skip[i] = size;
    }
    for (int i = 0; i < size - 1; i++)
    {
        skip[str2[i]] = size - i - 1;
    }

    return 0;
}