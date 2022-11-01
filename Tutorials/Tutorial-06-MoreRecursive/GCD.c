/*
  Tutorial 6 - Recursive Examples

  Code provided for ELEC-278 Tutorial at Queen's University

  @author AmirHossein Sojoodi
  @date 2022-10
*/

#include <stdio.h>

int gcd(int n1, int n2) {

  if (n2 == 0) {
    return n1;
  }
  else {
    return gcd(n2, n1 % n2);
  }

}

int main(void) {
  int n1, n2;
  printf("Enter two positive integers: ");
  scanf_s("%d", &n2);
  scanf_s("%d", &n1);
  printf("GCD of %d and %d is %d.", n1, n2, gcd(n1, n2));
  return 0;
}
