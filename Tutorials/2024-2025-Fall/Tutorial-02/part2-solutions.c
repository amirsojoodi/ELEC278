#include <stdio.h>
#include <stdlib.h>

int main() {
  // Feel free to change the size of the 2D array
  int rows = 3, cols = 3;

  // Allocate memory for the array of pointers to rows
  int **array =
      (int **)malloc(rows * sizeof(int *)); // we use double pointers because it
                                            // is a pointer to a pointer
  if (array == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return 1;
  } // check if memory allocation failed

  // Allocate memory for each row
  for (int i = 0; i < rows; i++) {
    array[i] = (int *)malloc(
        cols *
        sizeof(
            int)); // note that you can also use *(array+i) instead of array[i]
    if (array[i] == NULL) {
      fprintf(stderr, "Memory allocation failed\n");
      return 1;
    }
  } // check if memory allocation failed

  // Initialize the array with some values
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      array[i][j] =
          i * cols +
          j; // note you can also use *(*(array+i)+j) instead of array[i][j]
    }
  }

  // Print the array
  printf("The 2D array is:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", array[i][j]);
    }
    printf("\n");
  }

  // Free the allocated memory
  for (int i = 0; i < rows; i++) {
    free(array[i]);
  }
  free(array);

  return 0;
}