#ifndef STACK_H
#define STACK_H


#define STACK_LENGTH (20)
#define EMPTY (-1)

void stack_push(int x);
void stack_pop();
void stack_print();
int stack_top_return();
bool stack_is_empty();

#endif