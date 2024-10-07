#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

// Function to create a stack
struct Stack* createStack() {
  struct Stack* stack = ;  // to do: allocate memory for the stack
  stack->top = ;           // to do: use top to keep track of the stack size
  return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
  // to do
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
  // to do
}

// Function to push an element onto the stack
void push(struct Stack* stack, int item) {
  // to do
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
  // to do
}

// Function to peek the top element of the stack
int peek(struct Stack* stack) {
  // to do
}