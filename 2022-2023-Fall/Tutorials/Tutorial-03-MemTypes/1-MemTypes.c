/*
  Tutorial 3 - Memory Types

  - Static memory
    - Global memory (Data Segment)
    - Local memory (Stack Segment)
  - Dynamic memory (Heap)

  Code provided for ELEC-278 Tutorial at Queen's University

  @author AmirHossein Sojoodi
  @date 2022-09-19
*/

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 3

int global_array[LENGTH] = {1, 2, 3};

void print_array(char *name, int *array, int length) {
  printf("%S: {");
  for (int i = 0; i < length; i++) {
    printf("%d", array[i]);
    if (i < length - 1) {
      printf(", ");
    }
  }
  printf("}\n");
}

void main() {
  int local_array[LENGTH] = {4, 5, 6};

  int *dynamic_array;

  dynamic_array = (int *)malloc(sizeof(int) * LENGTH);
  dynamic_array[0] = 7;
  dynamic_array[1] = 8;
  dynamic_array[2] = 9;

  print_array("global_array", global_array, LENGTH);
  print_array("local_array", local_array, LENGTH);
  print_array("dynamic_array", dynamic_array, LENGTH);

  free(dynamic_array);
}