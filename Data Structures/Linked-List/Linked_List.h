#ifndef LINKED_LIST_H
#define LINKED_LIST_H


typedef struct Node
{
    int data;
    struct Node *next;

} Node;

Node *node_create( int data );
void node_find( Node *head, int data );
void node_print( Node *head );
void node_insert_at_tail( Node *head, int data );
Node *node_insert_at_head( Node *head, int data );
Node *node_delete_head( Node *head );
void node_delete( Node **head , int data);
void node_update( Node *head , int data , int new_data);

#endif
