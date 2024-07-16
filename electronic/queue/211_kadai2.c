#define QUEUE_SIZE 5
struct queue
{
    int array[QUEUE_SIZE]; // データが入る配列
    int wp;                // 次にデータを入れる場所の配列番号
    int quantity;          // データの個数
};

int enqueue(struct queue *obj, int data)
{
    // 残り領域があるか確認する．
    // データが自然数か確認する．
    // 配列にデータを保存する．
    // 最新のデータが入った場所の次の場所を指すように値を更新する．
    // データの個数カウントを増やす．
    // 返り値を返す．
    if (obj->quantity >= QUEUE_SIZE)
    {
        return -101;
    }
    if (data < 0)
    {
        return -102;
    }
    obj->array[obj->wp] = data;
    obj->wp = (obj->wp + 1) % QUEUE_SIZE;
    obj->quantity++;
    return -100;
}
int dequeue(struct queue *obj)
{
    // データが存在するかどうか確認する．
    // キューからデータをとりだす．
    // データの個数のカウントを減らす．
    // データもしくは返り値を返す．
    if (obj->quantity <= 0)
    {
        return -201;
    }
    int data = obj->array[0];
    obj->quantity--;
    obj->array[(obj->wp+QUEUE_SIZE - obj->quantity - 1) % QUEUE_SIZE] = 0;
    return data;
}
int initqueue(struct queue *obj)
{
    // キューのデータを入れる配列をすべて 0 に初期化する．
    // キューのデータ格納個数を 0 に初期化する
    // キューの wp ポインタを 0 に初期化する．
    for (int i = 0; i < QUEUE_SIZE; i++)
    {
        obj->array[i] = 0;
    }
    obj->quantity = 0;
    obj->wp = 0;
    return 0;
}
int showQueue(struct queue *obj)
{
    // 配列全体のデータを順に表示する．
    // データとデータの間に区切り文字「|」を表示する．
    for (int i = 0; i < QUEUE_SIZE; i++)
    {
        printf("%d", obj->array[i]);
        if (i < QUEUE_SIZE - 1)
        {
            printf("|");
        }
    }
    return 0;
}
void showResult(int result)
{
    // result の値に応じて，対応するエラーメッセージを表示する．
    switch (result)
    {
    case -100:
        printf("正常終了\n");
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
        printf("\n");
        break;
    }
}

int main(void)
{
    struct queue obj;
    int result;
    result = enqueue(&obj,40);
    initqueue(&obj);
    showQueue(&obj);
    printf("<40");
    showResult(result);
    result = enqueue(&obj,60);
    showQueue(&obj);
    printf("<60");
    showResult(result);
    result = enqueue(&obj,10);
    showQueue(&obj);
    printf("<10");
    showResult(result);
    result = enqueue(&obj,80);
    showQueue(&obj);
    printf("<80");
    showResult(result);
    result = enqueue(&obj,30);
    showQueue(&obj);
    printf("<30");
    showResult(result);
    result = enqueue(&obj,50);
    showQueue(&obj);
    printf("<50");
    showResult(result);
    result = dequeue(&obj);
    showQueue(&obj);
    printf(">%d", result);
    showResult(result);
    result = enqueue(&obj,1);
    showQueue(&obj);
    printf("<1");
    showResult(result);
    result = enqueue(&obj,2);
    showQueue(&obj);
    printf("<2");
    showResult(result);
    result = dequeue(&obj);
    showQueue(&obj);
    printf(">%d", result);
    showResult(result);
    result = dequeue(&obj);
    showQueue(&obj);
    printf(">%d", result);
    showResult(result);
    result = dequeue(&obj);
    showQueue(&obj);
    printf(">%d", result);
    showResult(result);
    result = dequeue(&obj);
    showQueue(&obj);
    printf(">%d", result);
    showResult(result);
    result = dequeue(&obj);
    showQueue(&obj);
    printf(">%d", result);
    showResult(result);
    result = dequeue(&obj);
    showQueue(&obj);
    printf(">%d", result);
    showResult(result);
    result = dequeue(&obj);
    showQueue(&obj);
    printf(">%d", result);
    showResult(result);
    result = dequeue(&obj);
    showQueue(&obj);
    printf(">%d", result);
    showResult(result);
    result = enqueue(&obj,200);
    showQueue(&obj);
    printf("<200");
    showResult(result);
    result = enqueue(&obj,300);
    showQueue(&obj);
    printf("<300");
    showResult(result);
    result = enqueue(&obj,-400);
    showQueue(&obj);
    printf("<-400");
    showResult(result);
    result = enqueue(&obj,500);
    showQueue(&obj);
    printf("<500");
    showResult(result);
    return 0;
}