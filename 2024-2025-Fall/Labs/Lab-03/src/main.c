#include "stack.h"
#include <stdio.h>
#include <string.h>

// Define the enum for categories of video game actions
typedef enum { PUNCH, KICK, WILD, DOUBLE, TRIPLE, HIT } Category;

// Define the structure for an action
typedef struct {
  Category name;
  int x;
} Action;

int calPoints(Action actions[], int actionSize);

int main() {
  // Test cases to evaluate stack operations
  struct Stack* stack = createStack();

  push(stack, 10);
  push(stack, 20);
  push(stack, 30);

  printf("%d popped from stack\n", pop(stack));
  printf("Top element is %d\n", peek(stack));

  // Test case to evaluate game score
  Action actions[] = {{PUNCH, 0}, {KICK, 0}, {DOUBLE, 0}, {TRIPLE, 0}, {WILD, 10},
                      {KICK, 0},  {KICK, 0}, {HIT, 3},    {DOUBLE, 0}};
  int actionSize = 9;
  printf("Total Points: %d\n", calPoints(actions, actionSize));

  return 0;
}

int calPoints(Action actions[], int actionSize) {
  // to do
}