#include <stdio.h>
#include <stdlib.h>

int main() {
  // Feel free to change the size of the 2D array
  int rows = 3, cols = 3;

  // To do: allocate memory for the array of pointers to rows
  int **array;
  if (array == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return 1;
  } // check if memory allocation failed

  // To do: allocate memory for each row
  for (int i = 0; i < rows; i++) {
    // To do
    if (array[i] == NULL) {
      fprintf(stderr, "Memory allocation failed\n");
      return 1;
    }
  } // check if memory allocation failed

  // to do: initialize the array with some values

  // To do: print the array

  // To do: free the allocated memory

  return 0;
}