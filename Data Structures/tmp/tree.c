#include "tree.h"
#include "deque.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

  TreeNode *root = node_create(4);
  DequeNode *head = NULL;
  DequeNode *tail = head;

  bst_insert(node_create(3), root);
  bst_insert(node_create(6), root);
  bst_insert(node_create(2), root);
  bst_insert(node_create(5), root);
  bst_insert(node_create(7), root);

  dp(head);

  return 0;
}

TreeNode *node_create(int value) {
  TreeNode *node = malloc(sizeof(TreeNode));
  *node = (TreeNode){value, NULL, NULL};
  return node;
}

void bst_insert(TreeNode *node, TreeNode *root) {
  if (root == NULL)
    return;

  if (node->data <= root->data)
    node_add_left(node, root);

  if (node->data >= root->data)
    node_add_right(node, root);

  return;
}

void node_add_right(TreeNode *node, TreeNode *root) {
  TreeNode *cursor = root;

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
void node_add_left(TreeNode *node, TreeNode *root) {
  TreeNode *cursor = root;

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
