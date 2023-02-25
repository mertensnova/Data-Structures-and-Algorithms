#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Stack.h"

int top = EMPTY;
int array[STACK_LENGTH];

int main()
{
    stack_push(6);
    stack_push(999);

    stack_pop();
    stack_pop();
   
    stack_print();

    return 0;
}

void stack_print()
{
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
    if (top < stack_is_empty())
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

bool stack_is_empty()
{
    if (top != EMPTY)
        return false;

    return true;
}