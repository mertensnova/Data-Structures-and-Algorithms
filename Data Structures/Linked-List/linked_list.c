#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "Linked_List.h"

int main( int argc, char *argv[] )
{
    Node *head = NULL;
    Node *tmp;

    tmp = create_node( 1 );
    head = tmp;

    
    for (int i = 2; i < 20; i++)
        head = insert_node_at_head(head,i);
    
    // find_node( head, atoi(argv[1]) );   
    head = delete_head_node( head ); 
    delete_node( &head, 17); 
    print_nodes( head );

    return 0;
}

void find_node( Node *head, int data )
{
    Node *tmp = head;
    bool found = false;
    int data_found;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        if (tmp->data == data)
        {
           found = true;
           data_found = tmp->data;
        }
    }

    if ( found )
       printf("Data %d found at memory address %p\n",data_found,&tmp->data);
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

void insert_node_at_tail( Node *head, int data )
{

    Node *tmp = head;
    Node *new_node;
    while ( tmp->next != NULL )
        tmp = tmp->next;
    
    new_node = create_node( data );
    tmp->next = new_node;
}

Node *insert_node_at_head( Node *head, int data )
{

    Node *tmp = head;
    Node *new_node  = create_node(data);
    new_node->next = tmp;
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

Node *delete_head_node( Node *head )
{
    Node *tmp = head;
    Node *tmp_2 = tmp;
    tmp = tmp->next;
    tmp_2 = NULL;

    return tmp;
}

void delete_node( Node **head , int data)
{  
    Node *tmp = *head; 
    Node *prev = *head;
    Node *curr = *head;
    bool deleted = false;

    while (tmp->data != data)
    {
        tmp = tmp->next;
        if (tmp->data == data)
        {
            deleted = true;     
            curr = curr->next; 
            prev->next = curr->next;
        }       
    }

    if ( deleted )
        printf("Data %d has been deleted at memory address %p\n",curr->data,&curr->data);
    else
        printf("Not found");

    free(curr);
    curr = NULL;
}