#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Queue.h"


// First In First Out

int array[QUEUE_LENGTH];
int rear = -1;
int front = -1;

int main(void)
{

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    dequeue();
    dequeue();
    enqueue(5);
    enqueue(6);
    print_queue();    
    return 0;
}

void enqueue(int x)
{
    if ((rear + 1) % QUEUE_LENGTH  == front)
    {
        printf("Error: Queue is full\n");
        return;
    }
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }

    rear = (rear+1) % QUEUE_LENGTH;
    array[rear] = x;
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Error: Queue is empty\n");
        return;
    }
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
        front = (front + 1) % QUEUE_LENGTH;
}

int queue_front()
{
    printf("First number %d\n",array[front + 1]);
    return array[front + 1];
}

void print_queue()
{
   int count = (rear + QUEUE_LENGTH - front) % QUEUE_LENGTH + 1;
	for(int i = 0; i < count; i++)
	{
		int index = (front + i ) % QUEUE_LENGTH; // Index of element while travesing circularly from front
		printf("%d=>",array[index]);
	}
}