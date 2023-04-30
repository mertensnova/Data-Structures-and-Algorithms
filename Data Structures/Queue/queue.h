#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *node_create(int value);
void enqueue(Node *node, Node **out_tail, Node **out_head);
Node *deque(Node *head, Node **out_head);
int peek(Node *head);

#endif
