/*
  Tutorial 10

  Code provided for ELEC-278 Tutorial at Queen's University

  Adapted from David Athersych
  @author AmirHossein Sojoodi
  @date 2022-11
*/

#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}

void max_heapify(int *arr, int start, int end) {
  int parent = start;
  int child = parent * 2 + 1;
  while (child <= end) {
    if (child + 1 <= end && arr[child] < arr[child + 1]) child++;
    if (arr[parent] < arr[child])
      return;
    else {
      swap(&arr[parent], &arr[child]);
      parent = child;
      child = parent * 2 + 1;
    }
  }
}

void heap_sort(int *arr, int len) {
  int i;
  for (i = len / 2 - 1; i >= 0; i--) max_heapify(arr, i, len - 1);
  for (i = len - 1; i > 0; i--) {
    swap(&arr[0], &arr[i]);
    max_heapify(arr, 0, i - 1);
  }
}

// Driver program to test above
int main() {
  int keys[] = {15, 10, 20, 8, 12, 16, 25};
  int len = sizeof(keys) / sizeof(keys[0]);
  int* heap = (int*)malloc(len * sizeof(int));

  heap_sort(keys, len);

  for (int i = 0; i < len; i++) printf("%d ", keys[i]);
  printf("\n");

  return 0;
}