#include <stdio.h>
#define STR_NUM 2500


char teststr[STR_NUM] = "In recent years, the push for renewable energy has gained significant momentum worldwide. Governments, corporations, and environmental organizations are increasingly recognizing the urgent need to transition from fossil fuels to sustainable energy sources. The latest developments in solar, wind, and hydroelectric power are making this transition more feasible and promising.One of the most notable advancements is in solar energy technology. New high-efficiency solar panels are now capable of converting more sunlight into electricity than ever before. This increased efficiency, combined with decreasing production costs, is making solar power a viable option for both residential and commercial use. Additionally, innovative storage solutions are addressing one of the key challenges of solar energyits intermittent nature. Advanced battery systems are now able to store excess energy generated during sunny periods, providing a reliable power source even when the sun is not shining.Wind energy is also seeing significant improvements. Modern wind turbines are designed to capture wind more effectively and operate in a wider range of wind conditions. Offshore wind farms, in particular, are emerging as a major source of renewable energy. These farms take advantage of stronger and more consistent winds found over the ocean, significantly boosting their energy output.Hydroelectric power remains a cornerstone of renewable energy strategies. Recent projects are focusing on small-scale hydroelectric systems that minimize environmental impact while providing power to remote and rural areas. These systems harness the energy of flowing water from rivers and streams, offering a sustainable and reliable energy source.The transition to renewable energy is not without its challenges. Infrastructure upgrades, regulatory changes, and significant financial investments are required to support this shift. However, the long-term benefits of reducing carbon emissions, combating climate change, and ensuring energy security are driving forces behind the global commitment to renewable energy.As the world continues to innovate and invest in renewable energy solutions, the vision of a sustainable future is becoming increasingly attainable. The combined efforts of technology advancements, policy support, and public awareness are set to transform the energy landscape, paving the way for a cleaner, greener planet.";
typedef struct args
{
    int debug;
    char *filename;
    char str1[STR_NUM];
    char str2[STR_NUM];
    int usefile;
    int isprintresult;
    int issame;
} args;

args arg;

int main(int argc, char *argv[])
{
    argselection(argc, argv, &arg);
    if(arg.issame == 1){
        return 0;
    }
    // 変数の宣言
    FILE *fp;
    char str[STR_NUM];
    // 変数の初期化
    char str2[100];
    strcpy(str2, arg.str2);
    for (int i = 0; i < STR_NUM; i++)
    {
        str[i] = 0;
    }
    // ファイルの読み込み
    // usefileが1の場合、ファイルを読み込む
    if (arg.usefile == 1)
    {
        fp = fopen(arg.filename, "r");
        if (fp == NULL)
        {
            printf("file open error\n");
            return 1;
        }
        while (fgets(str, STR_NUM, fp) != NULL)
        {
            if(arg.debug == 1){
                printf("str:%s", str);
            }
        }
        fclose(fp);
    }
    // usefileが0の場合、引数から文字列を読み込む
    else
    {
        for (int i = 0; i < STR_NUM; i++)
        {
            str[i] = 0;
        }
        strcpy(str, arg.str1);
    }
    // -dがある場合、読み込んだ文字列を表示する
    if (arg.debug == 1)
    {
        printf("str:%s\n", str);
    }
    // スキップテーブル作成
    int skip[256];
    int size = 0;
    while (str2[size] != 0)
    {
        size++;
    }
    for (int i = 0; i < 256; i++)
    {
        skip[i] = size;
    }
    for (int i = 0; i < size - 1; i++)
    {
        skip[(int)str2[i]] = size - i - 1;
    }
    // show skip table
    // 8列で表示
    printf("skip table\n");
    for (int i = 32; i < 127; i++)
    {
        printf("%c:%d\t", i, skip[i]);
        if (i % 8 == 7)
        {
            printf("\n");
        }
    }
    printf("\n");
    // ヤーッ！
    //見つけたところに色を付ける機能を追加させる
    int found[STR_NUM];
    for (int i = 0; i < STR_NUM; i++)
    {
        found[i] = 0;
    }
    int i = 0;
    int t = 0;
    while (t < STR_NUM)
    {
        if (i == size)
        {
            printf("find in %d\n", t+1);
            for (int j = 0; j < size; j++)
            {
                found[t + j] = 1;
            }
        }
        if (str[t + size - i - 1] == str2[size - i - 1])
        {
            i++;
        }
        else
        {
            i = 0;
            t += skip[(int)str[t + size - i - 1]];
        }
    }
    //見つからなかった場合は、見つからなかったと表示する
    int find = 0;
    for (int i = 0; i < STR_NUM; i++)
    {
        if (found[i] == 1)
        {
            find = 1;
        }
    }
    if (find == 0)
    {
        printf("not found\n");
    }
    //結果を表示する
    if (arg.isprintresult == 1)
    {
        for (int i = 0; i < STR_NUM; i++)
        {
            if (found[i] == 1)
            {
                printf("\033[31m%c\033[0m", str[i]);
            }
            else
            {
                printf("%c", str[i]);
            }
        }
        printf("\n");
    }


    return 0;
}

void argselection(int argc, char *argv[], args *arg)
{
    arg->debug = 0;
    arg->filename = "";
    arg->usefile = 0;
    arg->isprintresult = 0;
    strcpy(arg->str1, "");
    strcpy(arg->str2, "energy");
    //-fがあった場合、usefileを1にして、次の引数をfilenameに入れる
    //-fがない場合は第2に引数をstr1、第3引数をstr2に入れる
    //-fがある場合は第2引数をstr2に入れ、str1は空白のままにする
    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] == '-')
        {
            if (argv[i][1] == 'f')
            {
                arg->usefile = 1;
                arg->filename = argv[i + 1];
                i++;
            }
            else if (argv[i][1] == 'd')
            {
                arg->debug = 1;
            }
            else if (argv[i][1] == 'p')
            {
                arg->isprintresult = 1;
            }
        }
        else
        {
            if (arg->usefile == 0)
            {
                if (arg->str1[0] == '\0')
                {
                    strcpy(arg->str1, argv[i]);
                }
                else
                {
                    strcpy(arg->str2, argv[i]);
                }
            }
                strcpy(arg->str2, argv[i]);
        }
    }
    if (arg->debug == 1)
    {
        printf("debug mode\n");
        printf("filename:%s\n", arg->filename);
        printf("usefile:%d\n", arg->usefile);
        printf("str1:%s\n", arg->str1);
        printf("str2:%s\n", arg->str2);
    }
    if((strcmp(arg->str1, arg->str2) == 0) && arg->usefile == 0){
        //比較するものがないエラー
        printf("error: no string to compare\n");
        arg->issame = 1;
    }
    else{
        arg->issame = 0;
    }
    if(strcmp(arg->str1, "") == 0 && arg->usefile == 0){
        strcpy(arg->str1, teststr);
    }
}