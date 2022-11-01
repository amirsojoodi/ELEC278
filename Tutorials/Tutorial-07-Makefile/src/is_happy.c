#include <stdio.h>

int is_happy(int num) {
  if (num == 1) {
    return 1;
  } else if (num == 4) {
    return 0;
  }

  int sum = 0;
  for (; num > 0; num /= 10) {
    sum += (num % 10) * (num % 10);
  }
  return is_happy(sum);
}

int main() {

  int number = 0;

  scanf("%d", &number);

  while (number != -1) {
    int flag = is_happy(number);
    if (flag == 1) {
      printf("%d is happy!\n", number);
    } else {
      printf("%d is unhappy!\n", number);
    }
    scanf("%d", &number);
  }
}
