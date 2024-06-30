#include <malloc.h>
#include <stdio.h>
// データと次のキューのアドレスを指す構造体の宣言
struct queue
{
    int val;
    struct queue *addr;
};
struct queue *bottom_queue = NULL; // 最古のキューのアドレスを記憶しておくポインタ
struct queue *top_queue = NULL;    // 最新のキューのアドレスを記憶しておくポインタ
int enqueue(int data)
{
    int r_val = -100;                            // 返り値を宣言する
    struct queue *new_queue;                     // 新しく確保する領域（構造体）へのポインタを宣言する
    if (data < 0 /*挿入するデータが 0 以下であったとき*/) // 0 以下のデータが入力された時
    {
        r_val = -102; // 返り値を設定する
    }
    // 追加する領域を確保する
    /*malloc で構造体のオブジェクトの領域を確保して，確保失敗した時*/
    else if ((new_queue = (struct queue *)malloc(sizeof(struct queue))) == NULL)
    {
        // 確保できなかったとき
        r_val = -101;
    }
    else
    {
        // 新しいキューのデータ値として引数のデータを入れる(enqueue:2-1)
        new_queue->val = data;
        // 新しいキューのアドレス値として NULL を入れる(enqueue:2-2)
        new_queue->addr = NULL;
        // まだ 1 個のキューもない時
        if (bottom_queue == NULL)
        {
            // 新しいキューが最古であるので，最古のキューを指すアドレスを更新する(enqueue:4-1)
            bottom_queue = new_queue;
            // 新しいキューが最新であるので，最新のキューを指すアドレスを更新する(enqueue:4-2)
            top_queue = new_queue;
        }
        // 1 個以上のキューがあるとき
        else
        {
            // これまで最新だった領域に新しい領域を連結する(enqueue:3-1)
            top_queue->addr = new_queue;
            // 新しい領域が最新であるので，最新を指すアドレスに代入する(enqueue:3-2)
            top_queue = new_queue;

        }
    }

    return r_val;
}
int dequeue()
{
    int r_val = -200;         // 返り値を入れる変数を確保する
    struct queue *new_bottom; // 新たに最古になる領域を指すポインタを宣言する
    // 残りキューが 1 個の場合
    if (top_queue == bottom_queue && bottom_queue != NULL)
    {
        // 最古のデータを返り値にするために取り出す(dequeue:1-1)
        // データを取り出した後のキューを解放する(dequeue:1-2)
        // 最新のキューがないことを宣言する(dequeue:1-3)
        // 最古のキューがないことを宣言する(dequeue:1-4)
        
    }
    // 残りのキューが 2 個以上の場合
    else if (top_queue != NULL && bottom_queue != NULL)
    {
        // 最古のデータを返り値にするために取り出す(dequeue:2-1)
        // 新たに最古になるキューのアドレスを覚えておく(dequeue:2-2)
        // データを取り出した後のキューを解放する(dequeue:2-3)
        // 新たに最古のキューになるアドレスを更新する(dequeue:2-4)
    }
    // キューが既に空っぽの場合
    else if (bottom_queue == NULL)
    {
        r_val = -201;
    }
    // 予測しえないエラー
    else
    {
        r_val = -202;
    }
    return r_val;
}
int showQueue()
{
    // リスト全体のデータを順に表示する．
    // データとデータの間に区切り文字「|」を表示する．
}
void showResult(int result)
{
    // result の値に応じて，対応するエラーメッセージを表示する．
}
void freeQueue()
{
    struct queue *this_queue;
    while (bottom_queue != NULL)
    {
        // 今回開放したいキューのアドレスを取得
        // 解放後に最古になるキューのアドレスを更新
        // キューの領域を解放する
    }
}
int main()
{
    int result;
    result = enqueue(40);
    showQueue();
    printf("<40");
    showResult(result);
    result = enqueue(60);
    showQueue();
    printf("<60");
    showResult(result);
    result = enqueue(10);
    showQueue();
    printf("<10");
    showResult(result);
    result = enqueue(80);
    showQueue();
    printf("<80");
    showResult(result);
    result = enqueue(30);
    showQueue();
    printf("<30");
    showResult(result);
    result = enqueue(50);
    showQueue();
    printf("<50");
    showResult(result);
    result = dequeue();
    showQueue();
    printf(">%d", result);
    showResult(result);
    result = enqueue(1);
    showQueue();
    printf("<1");
    showResult(result);
    result = enqueue(2);
    showQueue();
    printf("<2");
    showResult(result);
    result = dequeue();
    showQueue();
    printf(">%d", result);
    showResult(result);
    result = dequeue();
    showQueue();
    printf(">%d", result);
    showResult(result);
    result = dequeue();
    showQueue();
    printf(">%d", result);
    showResult(result);
    result = dequeue();
    showQueue();
    printf(">%d", result);
    showResult(result);
    result = dequeue();
    showQueue();
    printf(">%d", result);
    showResult(result);
    result = dequeue();
    showQueue();
    printf(">%d", result);
    showResult(result);
    result = dequeue();
    showQueue();
    printf(">%d", result);
    showResult(result);
    result = dequeue();
    showQueue();
    printf(">%d", result);
    showResult(result);
    result = enqueue(200);
    showQueue();
    printf("<200");
    showResult(result);
    result = enqueue(300);
    showQueue();
    printf("<300");
    showResult(result);
    result = enqueue(-400);
    showQueue();
    printf("<-400");
    showResult(result);
    result = enqueue(500);
    showQueue();
    printf("<500");
    showResult(result);
    freeQueue();

    return 0;
}