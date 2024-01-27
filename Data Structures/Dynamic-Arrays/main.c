#include "vector.h"
#include <stdlib.h>


int main() {

  int *arr = vector_create(1);

  vector_push_back(5, &arr);
  vector_push_back(2, &arr);
  vector_push_back(3, &arr);
  vector_push_back(4, &arr);
  vector_push_back(12, &arr);
  vector_push_back(123, &arr);

  vector_pop_back(&arr);
  vector_pop_back(&arr);
  vector_pop_back(&arr);

  free(arr);
};


