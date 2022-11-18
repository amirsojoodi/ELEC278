/*
  Tutorial 10

  Code provided for ELEC-278 Tutorial at Queen's University

  Adapted from David Athersych
  @author AmirHossein Sojoodi
  @date 2022-11
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool check_min_heap(int A[], int i, int size) {
  if (2 * i + 2 > size) {
    return true;
  }

  bool left = (A[i] <= A[2 * i + 1]) && check_min_heap(A, 2 * i + 1, size);

  bool right = (2 * i + 2 == size) || (A[i] <= A[2 * i + 2] && check_min_heap(A, 2 * i + 2, size));

  return left && right;
}

int main() {
  int A[6] = {2, 3, 4, 5, 10, 15};
  int size = sizeof(A) / sizeof(A[0]);

  // start with index 0 (the root of the heap)
  int index = 0;

  if (check_min_heap(A, index, size)) {
    printf("The given array is a min-heap");
  } else {
    printf("The given array is not a min-heap");
  }
  return 0;
}
