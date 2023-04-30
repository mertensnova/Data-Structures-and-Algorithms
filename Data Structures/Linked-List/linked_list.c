#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"

int main(int argc, char *argv[]) {

  Node *head = NULL;

  node_insert_at_index(node_create(1), head, 0, &head);
  node_insert_at_index(node_create(2), head, 1, &head);
  node_insert_at_index(node_create(3), head, 2, &head);
  node_insert_at_index(node_create(4), head, 3, &head);

  node_insert_at_head(node_create(211), head, &head);
  node_insert_at_tail(node_create(5), head, &head);

  node_remove(0, head, &head);

  return 0;
}

Node *node_create(int value) {
  // Allocate a memory for the new node
  Node *node = malloc(sizeof(Node));
  // Init the new node. Set the data to value given and set next to NULL
  *node = (Node){value, NULL};
  return node;
}

int node_insert_at_index(Node *node, Node *head, int index, Node **out_head) {
  // Init the cursor node and current index
  Node *cursor = head;
  int cursor_index = 0;

  // If index is 0 or head is NULL / empty ,insert as new head
  if (*out_head == NULL || index == 0) {
    node->next = *out_head;
    *out_head = node;
    return -1;
  }

  // Increment the current index & update the cursor to the next node until it
  // reaches the index
  while (cursor_index < index - 1) {
    cursor = cursor->next;
    cursor_index++;
  }
  // Index not found, list wasn't long enough
  if (cursor_index != index - 1)
    return -1;

  // Insert the node
  node->next = cursor->next;
  cursor->next = node;
  return 0;
}

int node_insert_at_head(Node *node, Node *head, Node **out_head) {

  // If head is NULL set set new node to head
  if (*out_head == NULL) {
    node->next = *out_head;
    *out_head = node;
    return 0;
  }

  // Insert at head
  node->next = *out_head;
  *out_head = node;
  return 0;
}
int node_insert_at_tail(Node *node, Node *head, Node **out_head) {

  // Init the cursor node
  Node *cursor = head;

  // If head is NULL set set new node to head
  if (*out_head == NULL) {
    *out_head = node;
    return 0;
  }

  // Update the cursor to the next node til it reaches the tail
  while (cursor->next != NULL) {
    cursor = cursor->next;
  }

  cursor->next = node;
  return 0;
}

int node_get(int index, Node *head) {

  // Init the cursor node and current index
  int cursor_index = 0;
  Node *cursor = head;

  // if head is NULL or empty return -1
  if (cursor == NULL) {
    return -1;
  }

  // Update the cursor to the next node til it reaches the index
  while (cursor_index != index) {
    cursor = cursor->next;
    cursor_index++;
  }

  // Return node data
  return cursor->data;
}
int node_remove(int index, Node *head, Node **out_head) {
  // Init the cursor node and current index
  int cursor_index = 0;
  Node *cursor = head;

  // If head is NULL exit
  if (head == NULL)
    return -1;

  // If index is 0 set the remove the head node
  if (index == 0) {
    *out_head = cursor->next;
    return 0;
  }

  //  Update the cursor to the next node til it reaches the index
  while (cursor_index != index - 1) {
    cursor = cursor->next;
    cursor_index++;
  }

  // Remove the node
  cursor->next = cursor->next->next;
  return 0;
}
