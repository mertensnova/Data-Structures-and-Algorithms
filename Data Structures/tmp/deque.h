#ifndef QUEUE_H
#define QUEUE_H
#include "tree.h"

typedef struct DequeNode {
  TreeNode data;
  struct DequeNode *next;

} DequeNode;

DequeNode *deque_node_create(TreeNode *value);
void deque(DequeNode **out_head);
void enqueue(DequeNode *node, DequeNode **out_head, DequeNode **out_tail);
void dp(DequeNode *head);

#endif

