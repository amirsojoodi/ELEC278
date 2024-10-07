#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int* data;
  int front;     // index of first element
  int rear;      // index of last element
  int size;      // how much we have used
  int capacity;  // how much capacity we have available from the start
} MyCircularDeque;

// Initialize deque with maximum size k
MyCircularDeque* myCircularDequeCreate(int k) {
  MyCircularDeque* deque = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
  deque->data = (int*)malloc(k * sizeof(int));
  deque->front = 0;  // can you start-off with different numbers for front and rear?
  deque->rear = -1;
  deque->size = 0;
  deque->capacity = k;
  return deque;
}

// Check if deque is empty
bool myCircularDequeIsEmpty(MyCircularDeque* obj) { return obj->size == 0; }

// Check if deque is full
bool myCircularDequeIsFull(MyCircularDeque* obj) { return obj->size == obj->capacity; }

// Add an item at the front
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
  if (myCircularDequeIsFull(obj)) {
    return false;  // Deque is full
  }
  obj->front = (obj->front - 1 + obj->capacity) % obj->capacity;
  obj->data[obj->front] = value;
  obj->size++;
  return true;
}

// Add an item at the rear
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
  if (myCircularDequeIsFull(obj)) {
    return false;  // Deque is full
  }
  obj->rear = (obj->rear + 1) % obj->capacity;
  obj->data[obj->rear] = value;
  obj->size++;
  return true;
}

// Delete an item from the front
bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
  if (obj->size == 0) {
    return false;  // Deque is empty
  }
  obj->front = (obj->front + 1) % obj->capacity;
  obj->size--;
  return true;
}

// Delete an item from the rear
bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
  if (obj->size == 0) {
    return false;  // Deque is empty
  }
  obj->rear = (obj->rear - 1 + obj->capacity) % obj->capacity;
  obj->size--;
  return true;
}

// Get the front item
int myCircularDequeGetFront(MyCircularDeque* obj) {
  if (obj->size == 0) {
    return -1;  // Deque is empty
  }
  return obj->data[obj->front];
}

// Get the rear item
int myCircularDequeGetRear(MyCircularDeque* obj) {
  if (obj->size == 0) {
    return -1;  // Deque is empty
  }
  return obj->data[obj->rear];
}

// Free the deque
void myCircularDequeFree(MyCircularDeque* obj) {
  free(obj->data);
  free(obj);
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