#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Linked_List.h"

int main( void )
{
    Node *head = NULL;
    Node *tmp;

    Node *tmp_2  = head;

    // tmp = create_node( 2 );
    // head = tmp;

    tmp = create_node( 3 );
    while (tmp_2->next != NULL)
    {
        tmp_2 = tmp_2->next;
    }

    tmp_2 = tmp;
    // tmp_2->next = tmp;
    
    // tmp = create_node( 3 );
    // head->next->next = tmp;

    // tmp = create_node( 4 );
    // head->next->next->next = tmp;
    
    print_nodes( head );

    return 0;
}


Node *create_node( int data )
{
    Node *new_node = ( Node* ) malloc( sizeof( Node ) );
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

Node *insert_node_at_tail( Node *head, int data )
{
    Node *tmp = head;
    while ( tmp != NULL )
        tmp = tmp->next;
    
    Node *new_node = create_node( data );
    tmp = new_node;

    return tmp;
}

void print_nodes( Node *head )
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        printf("%d->",tmp->data);
        tmp = tmp->next;
    }

    printf("\n");
}