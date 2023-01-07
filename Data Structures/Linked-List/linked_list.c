#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "Linked_List.h"

int main( int argc, char *argv[] )
{
    Node *head = NULL;
    Node *tmp;

    tmp = node_create( 1 );
    head = tmp;

    
    for (int i = 2; i < 20; i++)
        head =  node_insert_at_head(head,i);
    
    node_print( head );

    return 0;
}

void node_find( Node *head, int data )
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

Node *node_create( int data )
{
    Node *new_node = ( Node* ) malloc( sizeof( Node ) );
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

void node_insert_at_tail( Node *head, int data )
{

    Node *tmp = head;
    Node *new_node;
    while ( tmp->next != NULL )
        tmp = tmp->next;
    
    new_node = node_create( data );
    tmp->next = new_node;
}

Node *node_insert_at_head( Node *head, int data )
{

    Node *tmp = head;
    Node *new_node  = node_create(data);
    new_node->next = tmp;
    tmp = new_node;

    return tmp;
}

void node_print( Node *head )
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        printf("%d->",tmp->data);
        tmp = tmp->next;
    }

    printf("\n");
}

Node *node_delete_head( Node *head )
{
    Node *tmp = head;
    Node *tmp_2 = tmp;
    tmp = tmp->next;
    tmp_2 = NULL;

    return tmp;
}

void node_delete( Node **head , int data)
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

void node_update( Node *head , int data , int new_data)
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
           tmp->data = new_data;
        }
    }

    if ( found )
       printf("Data %d have been updated to %d at memory address %p\n",data_found,new_data,&tmp->data);
    else
        printf("Not found");
}