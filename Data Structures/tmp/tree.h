#ifndef TREE_H
#define TREE_H

#include <stdbool.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;

} TreeNode;

// Insertion
TreeNode *node_create(int value);
void node_add_right(TreeNode *node, TreeNode *root);
void node_add_left(TreeNode *node, TreeNode *root);
void bst_insert(TreeNode *node, TreeNode *root);

// DFS
void traverse_pre(TreeNode *root);
void traverse_inorder(TreeNode *root);
void traverse_post(TreeNode *root);
TreeNode *bst_find(TreeNode *root, int value);

void node_delete(TreeNode *root, int value);

void bfs(TreeNode *root);

#endif
