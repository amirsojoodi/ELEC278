/*
  Tutorial 6 - Recursive Examples

  Code provided for ELEC-278 Tutorial at Queen's University

  @author AmirHossein Sojoodi
  @date 2022-10
*/

#include <stdio.h>
#define N 5

void printCombination(int out[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", out[i]);
  }

  printf("\n");
}

void printCombinations(int i, int n, int out[], int index) {
  if (n == 0) {
    printCombination(out, index);
    return;
  }

  for (int j = i; j <= n; j++) {
    out[index] = j;
    printCombinations(j, n - j, out, index + 1);
  }
  return;
}

int main(void) {
  int out[N];
  printCombinations(1, N, out, 0);

  return 0;
}