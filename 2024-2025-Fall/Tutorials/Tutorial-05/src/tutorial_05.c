#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  // complete
} MyCircularDeque;

// Initialize deque with maximum size k
MyCircularDeque* myCircularDequeCreate(int k) {
  // to do
}

// Check if deque is empty
bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
  // to do
}

// Check if deque is full
bool myCircularDequeIsFull(MyCircularDeque* obj) {
  // to do
}

// Add an item at the front
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
  // to do
}

// Add an item at the rear
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
  // to do
}

// Delete an item from the front
bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
  // to do
}

// Delete an item from the rear
bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
  // to do
}

// Get the front item
int myCircularDequeGetFront(MyCircularDeque* obj) {
  // to do
}

// Get the rear item
int myCircularDequeGetRear(MyCircularDeque* obj) {
  // to do
}

// Free the deque
void myCircularDequeFree(MyCircularDeque* obj) {
  // to do
}

int main() {
  MyCircularDeque* deque = myCircularDequeCreate(3);  // Size 3

  printf("Insert Last 1: %d\n", myCircularDequeInsertLast(deque, 1));    // returns true
  printf("Insert Last 2: %d\n", myCircularDequeInsertLast(deque, 2));    // returns true
  printf("Insert Front 3: %d\n", myCircularDequeInsertFront(deque, 3));  // returns true
  printf("Insert Front 4: %d\n",
         myCircularDequeInsertFront(deque, 4));  // returns false, queue is full

  printf("Get Rear: %d\n", myCircularDequeGetRear(deque));  // returns 2
  printf("Is Full: %d\n", myCircularDequeIsFull(deque));    // returns true

  printf("Delete Last: %d\n", myCircularDequeDeleteLast(deque));         // returns true
  printf("Insert Front 4: %d\n", myCircularDequeInsertFront(deque, 4));  // returns true
  printf("Get Front: %d\n", myCircularDequeGetFront(deque));             // returns 4

  myCircularDequeFree(deque);  // Free the deque
  return 0;
}