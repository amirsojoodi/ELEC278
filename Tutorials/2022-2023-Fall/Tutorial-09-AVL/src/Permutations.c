#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int length) {
  for (int i = 0; i < length; i++) {
    printf("%2d ", arr[i]);
  }
  printf("\n");
}

void produce_perm(int *arr, int length, int bits, int depth, int index) {
  if (depth == bits) {
    print_array(arr, length);
    return;
  }

  for (int i = index; i < length; i++) {
    arr[i] = 1;
    produce_perm(arr, length, bits, depth + 1, i + 1);
    arr[i] = 0;
  }
  return;
}

int main() {
  int arr[7] = {0, 0, 0, 0, 0, 0, 0};
  produce_perm(arr, 7, 2, 0, 0);
  return 0;
}