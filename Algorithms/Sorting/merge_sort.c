#include <stddef.h>
#include <stdio.h>

void merge_sort(int *arr, size_t size);
void print(int *arr, size_t size);

int main(int argc, char *argv[]) {
  int arr[] = {22, 33, 53, 1, 12, 55, 90, 2, 8, 21, 87, 99, 102, 23};

  merge_sort(arr, sizeof(arr) / sizeof(arr[0]));
  return 0;
}

void merge_sort(int *array, size_t size) {}

void print(int *arr, size_t size) {
  for (int i = 0; i < size; ++i) {
    printf("%i,", arr[i]);
  }

  printf("\n");
}
