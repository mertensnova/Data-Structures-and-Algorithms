#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main()
{
    Node *root = node_create(7);

    node_add_left(node_create(23), &root, root);
    node_add_left(node_create(4), &root, root);
    node_add_left(node_create(5), &root, root);

    node_add_right(node_create(3), &root, root);
    node_add_right(node_create(18), &root, root);
    node_add_right(node_create(21), &root, root);

    printf("Pre Order\t");
    traverse_pre(root);
    printf("\n");

    printf("In Order\t");
    traverse_inorder(root);
    printf("\n");

    printf("Post Order\t");
    traverse_post(root);
    printf("\n");
    return 0;
}

Node *node_create(int value)
{
    Node *node = malloc(sizeof(Node));
    *node = (Node){value, NULL, NULL};
    return node;
}
void node_add_right(Node *node, Node **out_root, Node *root)
{
    Node *cursor = root;

    while (cursor->right != NULL && cursor->left != NULL)
        cursor = cursor->right;

    if (cursor->left == NULL)
    {
        cursor->left = node;
        return;
    }
    if (cursor->right == NULL)
    {
        cursor->right = node;
        return;
    }

    return;
}
void node_add_left(Node *node, Node **out_root, Node *root)
{
    Node *cursor = root;

    while (cursor->left != NULL && cursor->right != NULL)
        cursor = cursor->left;

    if (cursor->left == NULL)
    {
        cursor->left = node;
        return;
    }

    if (cursor->right == NULL)
    {
        cursor->right = node;
        return;
    }
}

void traverse_pre(Node *root)
{
    Node *cursor = root;

    if (cursor == NULL)
        return;

    printf("%d -> ", cursor->data);
    traverse_pre(cursor->left);
    traverse_pre(cursor->right);
}
void traverse_inorder(Node *root)
{
    Node *cursor = root;

    if (cursor == NULL)
        return;

    traverse_pre(cursor->left);
    printf("%d -> ", cursor->data);
    traverse_pre(cursor->right);
}
void traverse_post(Node *root)
{
    Node *cursor = root;

    if (cursor == NULL)
        return;

    traverse_pre(cursor->left);
    traverse_pre(cursor->right);
    printf("%d -> ", cursor->data);
}
