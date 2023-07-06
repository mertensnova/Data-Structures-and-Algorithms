#ifndef TREE_H
#define TREE_H

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

} Node;

Node *node_create(int value);
void node_add_right(Node *node, Node **out_root, Node *root);

void node_add_left(Node *node, Node **out_root, Node *root);
void traverse_pre(Node *root);
void traverse_inorder(Node *root);
void traverse_post(Node *root);

#endif