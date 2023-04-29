#include "Stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Last In First Out

int length = 0;

int main() {

  Node *head = NULL;

  stack_push(1, &head);
  stack_push(2, &head);
  stack_push(3, &head);

  stack_pop(&head);
  stack_print(head);
  return 0;
}

Node *new_node(int value) {

  Node *node = (Node *)malloc(sizeof(Node));
  node->data = value;
  node->next = NULL;

  return node;
}
void stack_push(int value, Node **head) {
  Node *node = new_node(value);
  length++;
  if (*head == NULL) {
    *head = node;
    return;
  }
  node->next = (*head);
  (*head) = node;
}
void stack_pop(Node **head) {
  Node *tmp = *head;
  *head = tmp->next;

  length--;
}


void stack_print(Node *head) {
  Node *tmp = head;
  while (tmp != NULL) {
    printf("%d->", tmp->data);
    tmp = tmp->next;
  }
}

int stack_peek(Node *head) { return head->data; }
