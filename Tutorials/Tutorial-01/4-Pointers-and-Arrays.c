/*
  Tutorial 1 - Pointers and Arrays

  Code provided for ELEC-278 Tutorial at Queen's University

  @author AmirHossein Sojoodi
  @date 2022-09-12
*/

#include <stdio.h>
#define LENGTH 5

void print_array(int *array, int size){
  printf("\n");
  for (size_t i = 0; i < size; i++)
  {
    printf(" %d", array[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {

  int static_array[LENGTH] = {1, 2, 3, 4, 5};
  int *dynamic_array;

  dynamic_array = (int *) malloc (sizeof(int) * LENGTH);
  print_array(static_array, LENGTH);
  print_array(dynamic_array, LENGTH);

  for (int i = 0; i < LENGTH; i++)
  {
    dynamic_array[i] = static_array[i];
    // *dynamic_array++ = static_array[i]; // What does this line do? any side-effect?
  }
  
  print_array(dynamic_array, LENGTH);

  free(dynamic_array);

  return 0;
}