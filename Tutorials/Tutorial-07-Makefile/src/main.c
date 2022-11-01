#include <stdio.h>

// #define DEBUG 1

int main() {
  printf("Hello Makefile!!!\n");

#ifdef DEBUG
  printf("In Debug mode!\n");
#endif

  return 0;
}