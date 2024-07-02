#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

int main(void){
    FILE * fp;
    char str[88799][15];
    float data[88799][2];
    int num[88799];
    int hash[100];
    fp = fopen("./dist.all.last.txt", "r");
    if (fp == NULL){
        printf("ファイルを開けませんでした\n");
        return 1;
    }
    //ファイルを読み込む。スペース区切りで列が入っているため一列目だけを取り出してstrに格納
    for(int i = 0; i < 88799; i++){
        fscanf(fp, "%s %f %f %d",str[i],&data[i][0],&data[i][1],&num[i]);
    }
    fclose(fp);
    fp = fopen("./hash.txt", "w");
    for(int i = 0; i < 88799; i++){
        fprintf(fp,"%d\n",(str[i][0] + str[i][1] + str[i][2] + str[i][3] + str[i][4] + str[i][5] + str[i][6] + str[i][7] + str[i][8] + str[i][9] + str[i][10] + str[i][11] + str[i][12] + str[i][13] + str[i][14])%100);
    }
    fclose(fp);
    for(int i = 0; i < 100; i++){
        hash[i] = 0;
    }
    for(int i = 0; i < 88799; i++){
        hash[(str[i][0] + str[i][1] + str[i][2] + str[i][3] + str[i][4] + str[i][5] + str[i][6] + str[i][7] + str[i][8] + str[i][9] + str[i][10] + str[i][11] + str[i][12] + str[i][13] + str[i][14])%100]++;
    }
    fp = fopen("./test.csv", "w");
    for(int i = 0; i < 100; i++){
        fprintf(fp,"%d,\n",hash[i]);
    }
    
    return 0;
}