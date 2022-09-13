/*
  Tutorial 1 - Function Pointers

  Code provided for ELEC-278 Tutorial at Queen's University

  Adapted from David Athersych
  @author AmirHossein Sojoodi
  @date 2022-09-12
*/

#include <stdio.h>

int add(int x, int y) { return x + y; }

int sub(int x, int y) { return x - y; }

int multiply(int a, int b) { return a * b; }

int modulo(int k, int m) { return k % m; }

int main(int argc, char* argv[]) {
  
  int (*f)(int, int);
  int a, b, c;

  a = 20;
  b = 30;
  f = add;
  c = f(a, b);
  printf("%d %d (add) %d\n", a, b, c);

  a = 20;
  b = 30;
  f = sub;
  c = f(a, b);
  printf("%d %d (subtract) %d\n", a, b, c);

  a = 90;
  b = 3;
  f = multiply;
  c = f(a, b);
  printf("%d %d (multiply) %d\n", a, b, c);

  a = 900;
  b = 301;
  f = modulo;
  c = f(a, b);
  printf("%d %d (remainder) %d\n", a, b, c);

  return 0;
}