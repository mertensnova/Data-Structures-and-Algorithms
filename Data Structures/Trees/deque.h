#ifndef QUEUE_H
#define QUEUE_H
#include "tree.h"

typedef struct QueueNode {
  Node data;
  struct QueueNode *next;
} QueueNode;

QueueNode *queue_node_create(Node value);
void enqueue(QueueNode *node, QueueNode **out_tail, QueueNode **out_head);
QueueNode *deque(QueueNode *head, QueueNode **out_head);
//int peek(QueueNode *head);

#endif
