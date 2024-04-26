#ifndef QUEUE_H
#define QUEUE_H
#include "tree.h"

extern int size;

typedef struct DequeNode {
  TreeNode data;
  struct DequeNode *next;
} DequeNode;


DequeNode *deque_node_create(TreeNode *value);
void enqueue(DequeNode *node, DequeNode **out_head, DequeNode **out_tail);
void dp(DequeNode *head);

DequeNode *deque(DequeNode **out_head);
#endif

