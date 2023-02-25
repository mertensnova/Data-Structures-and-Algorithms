#ifndef QUEUE_H
#define QUEUE_H

#define QUEUE_LENGTH (10)

void enqueue(int x);
void dequeue();
int queue_front();
bool queue_is_empty();
bool queue_is_full();

#endif