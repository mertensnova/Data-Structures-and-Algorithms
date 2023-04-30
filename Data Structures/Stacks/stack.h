#ifndef STACK_H
#define STACK_H

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *node_create(int value);
int stack_push(Node *node, Node **out_head);
int stack_pop(Node **out_head);
int stack_peek(Node *head);

#endif
