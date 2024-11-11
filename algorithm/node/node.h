#ifndef NODE_H
#define NODE_H

typedef struct node
{
    int value;
    int next;
    int prev;
} Node;

Node* create_node(int value, int next, int prev);
int get_value(Node* node);
int get_next(Node* node);
int get_prev(Node* node);
void set_value(Node* node, int value);
void set_next(Node* node, int next);
void set_prev(Node* node, int prev);

#endif // NODE_H