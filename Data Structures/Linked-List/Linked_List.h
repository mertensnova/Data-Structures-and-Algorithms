#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
  int data;
  struct Node *next;

} Node;

Node *node_create(int value);
void node_insert_at_index(int value, int index, Node **head);
void node_insert_at_head(int value, Node **head);
void node_insert_at_tail(int value, Node **head);
int node_get(int index, Node **head);
void node_remove(int index, Node **head);
void node_print(Node *head);

#endif
