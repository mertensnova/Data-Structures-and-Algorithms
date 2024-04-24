#ifndef TREE_H
#define TREE_H

#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

} Node;

// Insertion
Node *node_create(int value);
void node_add_right(Node *node, Node *root);
void node_add_left(Node *node, Node *root);
void bst_insert(Node *node, Node *root);

// DFS
void traverse_pre(Node *root);
void traverse_inorder(Node *root);
void traverse_post(Node *root);
Node *bst_find(Node *root, int value);

void bfs(Node *root);

void node_delete(Node *root, int value);
#endif
