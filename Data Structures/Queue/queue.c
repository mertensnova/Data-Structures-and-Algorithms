#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Queue.h"


int array[QUEUE_LENGTH];
int rear = QUEUE_LENGTH;
int front = sizeof(array) / sizeof(array[0]);

int main(void)
{

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    enqueue(10);
    dequeue();
    enqueue(11);
    // enqueue(12);

    // queue_front();

    for (int i = 0; i <= sizeof(array) / sizeof(array[0]); i++)
        if (array[i] != 0) printf("%d->",array[i]);
    
    printf("\n");
    
    return 0;
}

void enqueue(int x)
{
    if (rear <= 0)
    {
        printf("Error: Queue overflow\n");
        return;
    }
    
    array[rear] = x;
    rear--;
}

void dequeue()
{
    if (rear == QUEUE_LENGTH)
    {
        printf("Error: Queue is empty\n");
        return;
    }
    
    printf("You took out %d\n",array[front]);
    array[front] = 0;
    front--;
}
int queue_front()
{
    printf("First number %d\n",array[front]);
    return array[front];
}