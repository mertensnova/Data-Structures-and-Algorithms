#include "vector.h"
#include <stdlib.h>


int *resize(int *array) {
  int *new_array = vector_create(tail * 2);

  for (int i = 0; i < tail; i++)
    new_array[i] = array[i];

  return new_array;
};

void vector_push_back(int value, int **__array) {

  if (tail == capcity)
    *__array = resize(*__array);

  (*__array)[tail++] = value;
};

void vector_pop_back(int **__array) {

  if (tail == 0)
    return;

  (*__array)[tail--] = 0;
}

int *vector_create(int size) {
  capcity = size;
  int *array = malloc(size * sizeof(int));
  return array;
};
