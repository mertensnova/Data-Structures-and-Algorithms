#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Queue.h"


int array[QUEUE_LENGTH];
int rear = -1;
int front = -1;

int main(void)
{

    enqueue(1);
    enqueue(2);

    // for (int i = 0; i <= sizeof(array) / sizeof(array[0]); i++)
    //     if (array[i] != -1 && array[i] != 0) printf("%d->",array[i]);
    
    printf("\n");
    
    return 0;
}

void enqueue(int x)
{
    if (queue_is_full)
    {
        printf("Error: Queue is full\n");
        return;
    }
    else if (queue_is_empty)
    {
        front = 0;
        rear = 0;
    }
    else
        rear = rear + 1;

    
    array[rear] = x;
}

void dequeue()
{
    if (queue_is_empty)
    {
        printf("Error: Queue is empty\n");
        return;
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }

    front++;
}
int queue_front()
{
    printf("First number %d\n",array[front]);
    return array[front];
}

bool queue_is_full()
{
    if (rear == QUEUE_LENGTH - 1)
        return true;
    
    return false;
}

bool queue_is_empty()
{
    if (front == -1 && rear == -1) 
        return true;
    
    return false;
}