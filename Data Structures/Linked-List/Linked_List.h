#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node
{
    int data;
    struct Node *next;

} Node;

Node *create_node( int data );
void print_nodes( Node *head );
Node *insert_node_at_tail( Node *head, int data );
// node *insert_at_head(node *head, int value);
// node *find_node(node *head, int value);
// void *update_node(node *head, int value, int new_value);
// void *delete_node(node **head, int numbers);
// void *insert_after_node(node *head, int value);
// void write_file(node *head);
// void read_file(node *head);

#endif
