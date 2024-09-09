#include <stdio.h>

void test(int *ptr) { 
  *ptr += 7; 
}

int main() {
  int x = 0;
  test(&x);
  printf("%d\n", x);
}