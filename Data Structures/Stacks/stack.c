#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
// Last In First Out

int main() {

  Node *head = NULL;

  stack_push(node_create(1), &head);
  stack_push(node_create(2), &head);
  stack_push(node_create(3), &head);

  stack_pop(&head);
  return 0;
}

Node *node_create(int value) {
  // Allocate a memory for the new node
  Node *node = malloc(sizeof(Node));
  // Init the new node. Set the data to value given and set next to NULL
  *node = (Node){value, NULL};
  return node;
}

int stack_push(Node *node, Node **out_head) {

  // If head is null set head to new node
  if (*out_head == NULL) {
    *out_head = node;
    return 0;
  }

  // Insert new node
  node->next = (*out_head);
  (*out_head) = node;
  return 0;
}
int stack_pop(Node **out_head) {
  Node *cursor = *out_head;
  *out_head = cursor->next;
  return 0;
}

int stack_peek(Node *out_head) { return out_head->data; }

