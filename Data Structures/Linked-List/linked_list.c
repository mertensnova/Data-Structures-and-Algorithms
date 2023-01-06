#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "Linked_List.h"

int main( void )
{
    Node *head = NULL;
    Node *tmp;


    tmp = create_node( 1 );
    head = tmp;

    for (int i = 2; i < 20; i++)
        insert_node_at_tail(head,i);

    
    find_node(head,10);
    
    print_nodes( head );

    return 0;
}

void *find_node( Node *head, int data )
{
    Node *tmp = head;
    bool found = false;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        if (tmp->data == data)
           found = true;
    }

    if ( found )
        printf("Data Found: %d at %p\n",tmp->data,&tmp->data);
    else
        printf("Not found");

}

Node *create_node( int data )
{
    Node *new_node = ( Node* ) malloc( sizeof( Node ) );
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

void *insert_node_at_tail( Node *head, int data )
{

    Node *tmp = head;
    Node *new_node;
    while ( tmp->next != NULL )
        tmp = tmp->next;
    
    new_node = create_node( data );
    tmp->next = new_node;
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