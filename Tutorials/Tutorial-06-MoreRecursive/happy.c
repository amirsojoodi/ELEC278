#include <stdio.h>

int is_happy(int n) {
  if (n == 1) {
    return 1;
  } else if (n == 16) {
    return 0;
  }
  int sum = 0;
  for (; n > 0; n /= 10) {
    sum += (n % 10) * (n % 10);
  }
  return is_happy(sum);
}

int main() {
  int num = 0;

  while (num != -1) {
    scanf("%d", &num);
    int flag = is_happy(num);
    if (flag == 1) {
      printf("The number is happy.\n");
    } else {
      printf("The number is unhappy.\n");
    }
  }

  return 0;
}