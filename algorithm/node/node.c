#include "node.h"
#include <stdlib.h>

// ノードを作成し、初期化する
Node* create_node(int value, int next, int prev) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return NULL; // メモリ割り当て失敗
    }
    newNode->value = value;
    newNode->next = next;
    newNode->prev = prev;
    return newNode;
}

// ノードの値を取得する
int get_value(Node* node) {
    if (node == NULL) {
        return -1; // エラー値
    }
    return node->value;
}

// ノードの次の要素を取得する
int get_next(Node* node) {
    if (node == NULL) {
        return -1; // エラー値
    }
    return node->next;
}

// ノードの前の要素を取得する
int get_prev(Node* node) {
    if (node == NULL) {
        return -1; // エラー値
    }
    return node->prev;
}

// ノードの値を設定する
void set_value(Node* node, int value) {
    if (node != NULL) {
        node->value = value;
    }
}

// ノードの次の要素を設定する
void set_next(Node* node, int next) {
    if (node != NULL) {
        node->next = next;
    }
}

// ノードの前の要素を設定する
void set_prev(Node* node, int prev) {
    if (node != NULL) {
        node->prev = prev;
    }
}