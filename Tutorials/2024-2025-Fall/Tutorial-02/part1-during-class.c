
#include <stdio.h>

int main() {
  // Define the size of the array
  // Feel free to change the size of the 2D array
  int rows = 3;
  int cols = 4;

  // To do: Declare and initialize the 2D array to hold int values

  // int array[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  int array[rows][cols];

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      array[i][j] = 0;
    }
  }

  printf("The 2D array is:\n");
  // To do: Print the array

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%4d", array[i][j]);
    }
    printf("\n");
  }

  return 0;
}