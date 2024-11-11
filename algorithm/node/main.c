#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// キューを初期化する関数
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// 新しいノードを作成する関数
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// キューに要素を追加する関数
void enqueue(Queue* q, int value) {
    Node* newNode = createNode(value);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

// キューから要素を削除する関数
int dequeue(Queue* q) {
    if (q->front == NULL) {
        return -1; // キューが空の場合
    }
    Node* temp = q->front;
    int value = temp->value;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return value;
}

// キューの先頭の要素を返す関数
int front(Queue* q) {
    if (q->front == NULL) {
        return -1; // キューが空の場合
    }
    return q->front->value;
}


int size(Queue* q) {
    int count = 0;
    Node* current = q->front;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// メイン関数
int main() {
    Queue* q = createQueue();
    const int NUM_ELEMENTS = 50000000; // 大量の要素数

    // 大量の要素をキューに追加
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        enqueue(q, i);
    }
    printf("After enqueuing %d elements, size: %d, front item: %d\n", NUM_ELEMENTS, size(q), front(q));

    // 要素の半分を削除
    for (int i = 0; i < NUM_ELEMENTS / 2; i++) {
        dequeue(q);
    }
    printf("After dequeuing half of the elements, size: %d, front item: %d\n", size(q), front(q));

    // 残りの要素をすべて削除
    while (front(q) != -1) { // キューが空になるまで削除
        dequeue(q);
    }
    printf("After dequeuing all elements, size: %d\n", size(q));

    return 0;
}