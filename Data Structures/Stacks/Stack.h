#ifndef STACK_H
#define STACK_H

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *new_node(int value);
void stack_push(int value, Node **head);
void stack_pop(Node **head);
void stack_print(Node *head);
int stack_peek(Node *head);
#endif
