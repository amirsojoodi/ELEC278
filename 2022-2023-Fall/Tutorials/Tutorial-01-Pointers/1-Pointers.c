/*
  Tutorial 1 - Pointers

  Code provided for ELEC-278 Tutorial at Queen's University

  Adapted from David Athersych
  @author AmirHossein Sojoodi
  @date 2022-09-12
*/

#include <stdio.h>

void main(void) {
  int x = 42;
  int *p = &x;  // p contains 2012
  p = p + 1;    // p contains ?
  p = p - 1;

  int y = 51;
  int *q = &y;
  if (p < q) {
    p++;
  }
  if (q < p) {
    q++;
  }

  printf("x = %d, y = %d\n", x , y);
  printf("*p = %d, *q = %d\n", *p, *q);
}