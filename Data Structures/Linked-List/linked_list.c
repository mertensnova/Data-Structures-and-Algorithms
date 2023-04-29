#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Linked_List.h"

int size = 0;
int main(int argc, char *argv[]) {

  Node *head = NULL;

  node_insert_at_index(1, 0, &head);
  node_insert_at_index(2, 1, &head);
  node_insert_at_tail(3, &head);

  node_remove(2, &head);
  node_print(head);

  return 0;
}

Node *node_create(int value) {
  Node *node = (Node *)malloc(sizeof(Node));

  node->data = value;
  node->next = NULL;
  return node;
}

void node_insert_at_index(int value, int index, Node **head) {
  Node *node = node_create(value);
  int i = 0;
  Node *prev = *head;

  size++;

  if (*head == NULL || index == 0) {
    node->next = *head;
    *head = node;
    return;
  }

  while (i < index - 1) {
    prev = prev->next;
    i++;
  }

  node->next = prev->next;
  prev->next = node;
}

void node_insert_at_tail(int value, Node **head) {
  node_insert_at_index(value, size, head);
}
void node_insert_at_head(int value, Node **head) {
  node_insert_at_index(value, 0, head);
}

int node_get(int index, Node **head) {
  int i = 0;
  Node *tmp = *head;
  if (*head == NULL) {
    return 1;
  }

  while (i != index) {
    tmp = tmp->next;
    i++;
  }
  return tmp->data;
}

void node_remove(int index, Node **head) {
  int i = 0;
  Node *prev = *head;

  if (*head == NULL || index > size)
    return;

  if (index == 0) {
    *head = prev->next;
    return;
  }

  while (i != index - 1) {
    prev = prev->next;
    i++;
  }
  prev->next = prev->next->next;
  size--;
}

void node_print(Node *head) {
  Node *tmp = head;

  while (tmp != NULL) {
    printf("%d->", tmp->data);
    tmp = tmp->next;
  }
  printf("\n");
}
