#include "deque.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

DequeNode *deque_node_create(TreeNode *value) {
  DequeNode *node = malloc(sizeof(DequeNode));
  node->data = *value;
  node->next = NULL;
  return node;
}

void enqueue(DequeNode *node, DequeNode **out_head, DequeNode **out_tail) {

  if (*out_head == NULL && *out_tail == NULL) {
    *out_tail = *out_head = node;
    return;
  }

  (*out_tail)->next = node;
  *out_tail = node;
  return;
}

void deque(DequeNode **out_head) {
  if (*out_head == NULL) {
    return;
  }
  *out_head= (*out_head)->next;
  return;
}

void dp(DequeNode *head) {
  DequeNode *tmp = head;
  while (tmp != NULL) {
    printf("%d->", tmp->data.data);
    tmp = tmp->next;
  }
  printf("\n");
  return;
}
void bfs(TreeNode *root){

};

