#include <stdio.h>
#define HEIGHT 5
#define TOWERS 3

struct Stack
{
    int data[HEIGHT];
    int volume;
};

void init(struct Stack *stack)
{
    // スタックのすべての要素の値を 0 にする
    // スタックに格納されているデータ数を 0 にする
    for (int i = 0; i < HEIGHT; i++)
    {
        stack->data[i] = 0;
    }
    stack->volume = 0;
}

int push(struct Stack *stack, int number)
{
    // データを最上位に積み込む
    // データの個数を増やす
    if (stack->volume >= HEIGHT)
    {
        return -1;
    }
    stack->data[stack->volume] = number;
    stack->volume++;
    return 0;
}

int pop(struct Stack *stack)
{
    // 格納されているデータ個数のカウントを減らす
    // 取り出すデータを取り出す
    // 取り出した場所を初期化する
    if (stack->volume == 0)
    {
        return -1;
    }
    stack->volume--;
    int result = stack->data[stack->volume];
    stack->data[stack->volume] = 0;
    return result;
}

void printStack(struct Stack stack)
{
    // スタックに格納されている値をスタックされている順番に 1 行に表示
    for (int i = 0; i <HEIGHT; i++)
    {
        printf("%d ", stack.data[i]);
    }
    printf("\n");
}

// void pushTest(struct Stack *stack, int num)
// {
//     printf("push (%d) ", num);
//     if (push(stack, num) == 0)
//     {
//         printf("SUCCESS\n");
//     }
//     else
//     {
//         printf("FAILURE\n");
//     }
//     printf("data : ");
//     printStack(stack);
// }

// void popTest(struct Stack *stack)
// {
//     printf("pop ");
//     int result = pop(stack);
//     printf("(%d) ", result);
//     if (result == -1)
//     {
//         printf("FAILURE\n");
//     }
//     else
//     {
//         printf("SUCCESS\n");
//     }
//     printf("data : ");
//     printStack(stack);
// }

int top(struct Stack tower)
{
    return tower.data[tower.volume - 1];
}
int enableStack(struct Stack fromTower, struct Stack toTower)
{
    /* 移動可能である条件に応じて返り値を返す */
    if (fromTower.volume == 0)
    {
        return 0;
    }
    else if (toTower.volume == 0)
    {
        return 1;
    }
    else if (top(fromTower) < top(toTower))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int checkFinish(struct Stack tower, int blocks)
{
    // ブロックが初期状態と同じ状態かチェックする
    for (int i = 0; i < blocks; i++)
    {
        if (tower.data[i] != blocks - i)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int i;
    int count = 1;
    int fromNumber, toNumber;
    int tempNumber;
    int blocks;
    struct Stack tower[TOWERS];

    printf("段数を選んでください : 3,4,5:");
    scanf("%d", &blocks);
    /*3 塔を初期化する*/
    init(&tower[0]);
    init(&tower[1]);
    init(&tower[2]);
    /*第１塔に決められた個数をスタックする*/
    for (i = 0; i < blocks; i++)
    {
        push(&tower[0], blocks - i);
    }
    /*塔の初期状態を表示する*/
    for (i = 0; i < TOWERS; i++)
        {
            printf("%d : ", i + 1);
            printStack(tower[i]);
        }
    while (1)
    {
        // 今，何回目の移動であるかを数える．
        printf("count : %d\n", count);

        // 移動元と移動先を受け取る
        printf("移動元塔と移動先塔を入力してください。[? ?]:");
        scanf("%d %d", &fromNumber, &toNumber);

        // 移動元の塔から移動先の塔にデータを移動させる
        if (enableStack(tower[fromNumber - 1], tower[toNumber - 1]))
        {
            tempNumber = pop(&tower[fromNumber - 1]);
            push(&tower[toNumber - 1], tempNumber);
            count++;
        }
        else
        {
            printf("移動できません\n");
        }

        // 現在の塔の状態を表示する
        for (i = 0; i < TOWERS; i++)
        {
            printf("%d : ", i + 1);
            printStack(tower[i]);
        }
        // クリア判定をする
        if (checkFinish(tower[2], blocks))
        {
            printf("クリア\n");
            break;
        }
    }
}
