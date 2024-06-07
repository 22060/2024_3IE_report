#include <stdio.h>
#define HEIGHT 5
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
    for (int i = stack.volume - 1; i >= 0; i--)
    {
        printf("%d ", stack.data[i]);
    }
    printf("\n");
}

void pushTest( struct Stack *stack,int num)
{
    printf("push (%d) ",num);
    if(push(stack, num) == 0){
        printf("SUCCESS\n");
    }else{
        printf("FAILURE\n");
    }
    printf("data : ");
    printStack(*stack);
}

void popTest( struct Stack *stack)
{
    printf("pop ");
    int result = pop(stack);
    printf("(%d) ",result);
    if(result == -1){
        printf("FAILURE\n");
    }else{
        printf("SUCCESS\n");
    }
    printf("data : ");
    printStack(*stack);
}

int main()
{
    struct Stack stack;
    init(&stack);
    pushTest(&stack,10);
    pushTest(&stack,20);
    pushTest(&stack,30);
    pushTest(&stack,40);
    pushTest(&stack,50);
    pushTest(&stack,60);
    popTest(&stack);
    popTest(&stack);
    popTest(&stack);
    popTest(&stack);
    popTest(&stack);
    popTest(&stack);
    return 0;
}
