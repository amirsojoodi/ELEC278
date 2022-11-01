#include <stdio.h>

int binary_search(int array[], int start, int end, int num) {
  if (end < start) {
    return -1;
  }
  if (end == start) {
    if (array[end] == num) {
      return end;
    } else {
      return -1;
    }
  }
  int mid = (end + start) / 2;
  if (num == array[mid]) {
    return mid;
  } else if (num > array[mid]) {
    return binary_search(array, mid + 1, end, num);
  } else {
    return binary_search(array, start, mid - 1, num);
  }
}

int main() {
  int array[] = {1, 2, 3, 10, 23, 155, 899};

  int number = 0;

  scanf("%d", &number);

  while (number != -1) {
    int index = binary_search(array, 0, 7, number);
    if (index != -1) {
      printf("%d is in index %d!\n", number, index);
    } else {
      printf("%d doesn exist!\n", number);
    }
    scanf("%d", &number);
  }
}