#include <stdio.h>
#define QUEUE_SIZE 4
int queue[QUEUE_SIZE];
int quantity = 0;

// #define MAX_SIZE 1000000 // キューの最大サイズ
int enqueue(int data);       // キューにデータを追加する関数
int dequeue();               // キューからデータを取り出す関数
int initQueue();             // キューを初期化する関数
int showQueue();             // キューの中身を表示する関数
void showResult(int result); // 結果を表示する関数

// メイン関数
int main()
{
    // キューを初期化する
    initQueue();
    // キューにデータを追加する
    showResult(enqueue(1));
    showResult(enqueue(2));
    showResult(enqueue(3));
    showResult(enqueue(4));
    showResult(enqueue(5));
    // キューの中身を表示する
    // showQueue();
    // キューからデータを取り出す
    showResult(dequeue());
    showResult(dequeue());
    showResult(dequeue());
    showResult(dequeue());
    showResult(dequeue());
    // キューの中身を表示する
    // showQueue();
    return 0;
}

int enqueue(int data)
{
    // 残り領域があるか確認する
    if (quantity >= QUEUE_SIZE)
    {
        return -101;
    }
    // データが自然数か確認する
    if (data < 0)
    {
        return -102;
    }
    // 配列のキューにデータを保存する
    queue[quantity] = data;
    // キューのポインタをインクリメントする
    quantity++;
    // 返り値を返す
    return -100;
}

int dequeue(void)
{
    // データが存在するかどうか確認する．
    if (quantity <= 0)
    {
        return -201;
    }
    // キューからデータをとりだす．
    int data = queue[0];
    // データの個数カウントを減らす
    quantity--;
    // 取り出されたデータ部分を埋めるように再構築する
    for (int i = 0; i < quantity; i++)
    {
        queue[i] = queue[i + 1];
    }
    // 空き領域を初期化する．
    queue[quantity] = 0;
    // データもしくは返り値を返す
    return data;
}

int initQueue()
{
    // キューのデータを入れる配列をすべて 0 に初期化する．
    for (int i = 0; i < QUEUE_SIZE; i++)
    {
        queue[i] = 0;
    }
    // 格納データ個数を 0 に初期化する．
    quantity = 0;
    return 0;
}

int showQueue()
{
    // 配列全体のデータを順に表示する．
    // データとデータの間に区切り文字「|」を表示する．
    for (int i = 0; i < QUEUE_SIZE; i++)
    {
        printf("%d|", queue[i]);
    }
    return 0;
}

void showResult(int result)
{
    // result の値に応じて，対応するエラーメッセージを表示する．
    showQueue();
    printf("--> %d:", result);
    switch (result)
    {
    case -100:
        printf("enqueue 成功\n");
        break;
    case -101:
        printf("エラー：キューが満杯です\n");
        break;
    case -102:
        printf("エラー：データが自然数ではありません\n");
        break;
    case -201:
        printf("エラー：キューが空です\n");
        break;
    default:
        if (result < 0)
        {
            printf("エラー：不明なエラーです\n");
        }
        else
        {
            printf("dequeue(%d)\n", result);
        }
        break;
    }
}
