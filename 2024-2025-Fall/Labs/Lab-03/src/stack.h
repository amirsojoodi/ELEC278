#ifndef STACK_H
#define STACK_H

#define MAX 100

struct Stack {
  int top;
  int array[MAX];
};

struct Stack* createStack();
int isEmpty(struct Stack* stack);
int isFull(struct Stack* stack);
void push(struct Stack* stack, int item);
int pop(struct Stack* stack);
int peek(struct Stack* stack);

#endif  // STACK_H
