#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"

int top = EMPTY;
int array[STACK_LENGTH];

int main()
{

    stack_push(1);
    stack_push(2);
    stack_push(3);
    stack_push(4);
    stack_push(5);
    stack_push(6);


    int t = stack_top_return();
  
    printf("%d\n",t);

    return 0;
}

void stack_print()
{
    // Print an array
    // for (int i = -1; i <= top; i++)
    //     printf("%d\n",array[i]);

    // Print an array in reverse order
    for (int i = top - 1; i >= EMPTY; i--)
        printf("%d\n",array[i]);
}

void stack_push(int x)
{
    if (top == STACK_LENGTH - 1)
    {
        printf("Error: Buffer Overflow");
        return;
    }
    
    array[top] = x; 
    top++;  
}

void stack_pop()
{   
    if (top == EMPTY)
    {
        printf("Error: Stack is empty");
        return;
    }

    top--;
}

int stack_top_return()
{   
    return array[top - 1];
}