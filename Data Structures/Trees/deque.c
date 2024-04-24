#include "deque.h"
#include <stdio.h>
#include <stdlib.h>

QueueNode *queue_node_create(Node value) {
  QueueNode *node = malloc(sizeof(QueueNode));
  *node = (QueueNode){value, NULL};
  return node;
}

void enqueue(QueueNode *node, QueueNode **out_tail, QueueNode **out_head) {

  if (*out_tail == NULL && *out_head == NULL) {
    *out_tail = *out_head = node;
  }
  (*out_tail)->next = node;
  *out_tail = node;
}
QueueNode *deque(QueueNode *head, QueueNode **out_head) {
  QueueNode *cursor = head;
  *out_head = (*out_head)->next;
  cursor->next = NULL;
  return cursor;
}

//int peek(QueueNode *head) { return head->data; }
