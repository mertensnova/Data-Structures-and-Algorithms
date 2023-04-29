#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

int lenght = 0;
// First In First Out
int main(void) {

  Node *head = NULL;
  Node *tail = NULL;
  enqueue(1, &tail, &head);
  enqueue(2, &tail, &head);
  enqueue(3, &tail, &head);
  enqueue(4, &tail, &head);
  enqueue(5, &tail, &head);

  deque(&head);
  print_queue(head);
  return 0;
}

void enqueue(int value, Node **tail, Node **head) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = value;
  node->next = NULL;

  if (*tail == NULL && *head == NULL) {
    *tail = *head = node;
  } else {
    (*tail)->next = node;
    *tail = node;
  }
  lenght++;
}
Node *deque(Node **head) {
  Node *tmp = *head;
  *head = (*head)->next;
  tmp->next = NULL;
  lenght--;
  return tmp;
}
int peek(Node *head) { return head->data; }

void print_queue(Node *head) {

  Node *tmp = head;
  while (tmp != NULL) {
    printf("%d<-", tmp->data);
    tmp = tmp->next;
  }
}
