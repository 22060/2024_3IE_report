#include <stdio.h>
#define STR_NUM 2500
int main(int argc, char *argv[])
{
    //変数の宣言
    FILE *fp;
    char str[STR_NUM];
    int t = 0;
    //変数の初期化
    char str2[100] = "recent";
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
    //パワー！ヤーッ！
    for (int i = 0; i < STR_NUM; i++)
    {
        while (str[i + t] == str2[t])
        {
            t++;
        }
        if (t == 6)
        {
            printf("find in %d\n", i);
        }
        t = 0;
    }


    return 0;
}