#include <stdio.h>
#include <stdlib.h>

int main() {
  // Feel free to change the size of the 2D array
  int rows = 3, cols = 3;

  // scanf("%d", &rows);
  // scanf("%d", &cols);
  // printf("User entered these vals: %d %d\n", rows, cols);

  // To do: allocate memory for the array of pointers to rows
  int **array = (int **)malloc(rows * sizeof(int *));

  if (array == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return 1;
  } // check if memory allocation failed

  // To do: allocate memory for each row
  for (int i = 0; i < rows; i++) {
    array[i] = (int *)calloc(cols, sizeof(int));
    if (array[i] == NULL) {
      fprintf(stderr, "Memory allocation failed\n");
      return 1;
    }
  }

  // by the assumption that we are in bounds
  array[1][2] = 10;
  array[2][1] = -1;

  // To do: print the array
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%4d", array[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < rows; i++) {
    free(array[i]);
    array[i] = NULL;
  }
  free(array);
  array = NULL;

  // Access to the array would cause seg fault
  // array[2][1] = 5;
  // printf("%d\n", array[2][1]);

  return 0;
}