#include "tree.h"
#include "deque.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


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

void traverse_pre(TreeNode *root) {
  TreeNode *cursor = root;

  if (cursor == NULL)
    return;

  printf("%d -> ", cursor->data);
  traverse_pre(cursor->left);
  traverse_pre(cursor->right);
}
void traverse_inorder(TreeNode *root) {
  TreeNode *cursor = root;

  if (cursor == NULL)
    return;

  traverse_inorder(cursor->left);
  printf("%d -> ", cursor->data);
  traverse_inorder(cursor->right);
}
void traverse_post(TreeNode *root) {
  TreeNode *cursor = root;

  if (cursor == NULL)
    return;

  traverse_post(cursor->left);
  traverse_post(cursor->right);
  printf("%d -> ", cursor->data);

}

TreeNode *bst_find(TreeNode *root, int value) {
  if (!root)
    return NULL;

  if (root->data == value)
    return root;

  if (root->data <= value)
    return bst_find(root->right, value);

  return bst_find(root->left, value);
}

void bfs(TreeNode *root) {

  if (!root) {
    return;
  }

  DequeNode *node = malloc(sizeof(DequeNode));
  node->data = *root;
  node->next = NULL;

  DequeNode *head = node;
  DequeNode *tail = head;

  enqueue(node, &head, &tail);

  while (size > 0) {

    for (DequeNode *tmp = head; tmp != NULL; tmp = tmp->next) {
      DequeNode *curr = deque(&head);
      printf("%d -> ", tmp->data.data);

      if (curr->data.left) {
        DequeNode *left_node = deque_node_create(curr->data.left);
        enqueue(left_node, &head, &tail);
      }
      if (curr->data.right) {
        DequeNode *right_node = deque_node_create(curr->data.right);
        enqueue(right_node, &head, &tail);
      }
    }
  }
  printf("\n");
}
