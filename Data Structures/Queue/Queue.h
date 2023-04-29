#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node {
  int data;
  Node *next;
} Node;

void enqueue(int value, Node **tail, Node **head);
Node *deque(Node **head);
int peek(Node *head);
void print_queue(Node *head);

#endif
