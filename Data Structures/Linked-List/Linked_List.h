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
void *find_node( Node *head, int data );
void print_nodes( Node *head );
void *insert_node_at_tail( Node *head, int data );

#endif
