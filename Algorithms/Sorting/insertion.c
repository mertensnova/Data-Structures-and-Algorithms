#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

void insertion_sort(int *arr, size_t size);

void print(int *arr, size_t size);
int main(int argc, char *argv[]) {
  int arr[] = {22, 33, 53, 1, 12, 55, 90, 2, 8, 21, 87, 99, 102, 23};

  //int arr[] = {2, 3, 4, 1, 6};
  insertion_sort(arr, sizeof(arr) / sizeof(arr[0]));

  return 0;
}

void insertion_sort(int *array, size_t size) {

  print(array, size);
  for (int i = 0; i < size; ++i) {
    int j = i - 1;
    while (j >= 0 && array[j] > array[j+1]) {
      int tmp = array[j+1];
      array[j+1] = array[j];
      array[j] = tmp;
      j--;
    }
  }

  print(array, size);
}

void print(int *arr, size_t size) {
  for (int i = 0; i < size; ++i) {
    printf("%i,", arr[i]);
  }

  printf("\n");
};
