#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
  int data;
  struct Node *next;

} Node;

Node *node_create(int value);
int node_insert_at_index(Node *node, Node *head, int index, Node **out_head);
int node_insert_at_head(Node *node, Node *head, Node **out_head);
int node_insert_at_tail(Node *node, Node *head, Node **out_head);
int node_get(int index, Node *head);
int node_remove(int index, Node *head, Node **out_head);
#endif
