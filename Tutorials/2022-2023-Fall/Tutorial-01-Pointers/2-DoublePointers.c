/*
  Tutorial 1 - Double Pointers

  Code provided for ELEC-278 Tutorial at Queen's University

  Adapted from David Athersych

  @author AmirHossein Sojoodi
  @date 2022-09-12
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
  int x = -1;
  int y = -1;
  int *xp = &x;
  int *yp = &y;
  int **pp;
  int *pi[2];

  pi[0] = xp;
  pi[1] = yp;
  *pi[0] = 4;
  *pi[1] = 5;
  printf("x = %d, y = %d\n", x, y);

  pp = pi;  // or pp=&pi[0];

  **pp = 11;
  **pp++ = 90;
  **pp = 75;
  pi[0] = &y;
  **--pp = 35;
  printf("x = %d, y = %d\n", x, y);

  return 0;
}
