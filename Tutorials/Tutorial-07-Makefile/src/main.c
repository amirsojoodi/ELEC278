/*
  Tutorial 7 - Command Line compilation

  Code provided for ELEC-278 Tutorial at Queen's University

  @author AmirHossein Sojoodi
  @date 2022-10
*/

#include <stdio.h>

// #define DEBUG 1

int main() {
  printf("Hello Makefile!!!\n");

#ifdef DEBUG
  printf("In Debug mode!\n");
#endif

  return 0;
}