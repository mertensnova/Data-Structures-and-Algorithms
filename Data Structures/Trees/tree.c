#include "tree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  Node *root = node_create(4);
  bst_insert(node_create(3), root);
  bst_insert(node_create(6), root);
  bst_insert(node_create(2), root);
  bst_insert(node_create(5), root);
  bst_insert(node_create(7), root);

  traverse_pre(root);
  printf("\n");
  return 0;
}

Node *node_create(int value) {
  Node *node = malloc(sizeof(Node));
  *node = (Node){value, NULL, NULL};
  return node;
}

void node_delete(Node *root, int value) {}

void bst_insert(Node *node, Node *root) {
  if (root == NULL)
    return;

  if (node->data <= root->data)
    node_add_left(node, root);

  if (node->data >= root->data)
    node_add_right(node, root);

  return;
}

void node_add_right(Node *node, Node *root) {
  Node *cursor = root;

  while (cursor->right != NULL && cursor->left != NULL)
    cursor = cursor->right;

  if (cursor->left == NULL) {
    cursor->left = node;
    return;
  }
  if (cursor->right == NULL) {
    cursor->right = node;
    return;
  }

  return;
}
void node_add_left(Node *node, Node *root) {
  Node *cursor = root;

  while (cursor->left != NULL && cursor->right != NULL)
    cursor = cursor->left;

  if (cursor->left == NULL) {
    cursor->left = node;
    return;
  }

  if (cursor->right == NULL) {
    cursor->right = node;
    return;
  }
}

void traverse_pre(Node *root) {
  Node *cursor = root;

  if (cursor == NULL)
    return;

  printf("%d -> ", cursor->data);
  traverse_pre(cursor->left);
  traverse_pre(cursor->right);
}
void traverse_inorder(Node *root) {
  Node *cursor = root;

  if (cursor == NULL)
    return;

  traverse_inorder(cursor->left);
  printf("%d -> ", cursor->data);
  traverse_inorder(cursor->right);
}
void traverse_post(Node *root) {
  Node *cursor = root;

  if (cursor == NULL)
    return;

  traverse_post(cursor->left);
  traverse_post(cursor->right);
  printf("%d -> ", cursor->data);
}

Node *bst_find(Node *root, int value) {
  if (!root)
    return NULL;

  if (root->data == value)
    return root;

  if (root->data <= value)
    return bst_find(root->right, value);

  return bst_find(root->left, value);
}

