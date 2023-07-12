#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

// First In First Out
int main(void) {

  Node *head = NULL;
  Node *tail = NULL;
  enqueue(node_create(1), &tail, &head);
  enqueue(node_create(2), &tail, &head);
  enqueue(node_create(3), &tail, &head);
  enqueue(node_create(4), &tail, &head);
  enqueue(node_create(5), &tail, &head);

  deque(head, &head);
  return 0;
}

Node *node_create(int value) {
  // Allocate a memory for the new node
  Node *node = malloc(sizeof(Node));
  // Init the new node. Set the data to value given and set next to NULL
  *node = (Node){value, NULL};
  return node;
}

void enqueue(Node *node, Node **out_tail, Node **out_head) {

  // If tail and head is null set new node to head an tail
  if (*out_tail == NULL && *out_head == NULL) {
    *out_tail = *out_head = node;
  }

  // Insert node to the tail
  (*out_tail)->next = node;
  *out_tail = node;
}
Node *deque(Node *head, Node **out_head) {
  // Save the head in variable
  Node *cursor = head;

  // Remove node
  *out_head = (*out_head)->next;
  cursor->next = NULL;
  return cursor;
}

int peek(Node *head) { return head->data; }
