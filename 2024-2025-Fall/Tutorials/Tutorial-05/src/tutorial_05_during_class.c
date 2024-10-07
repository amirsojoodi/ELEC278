#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  // complete
} deque_t;

// Initialize deque with maximum size k
deque_t* deque_create(int k) {
  // to do
}

// Check if deque is empty
bool deque_is_empty(deque_t* deque) {
  // to do
}

// Check if deque is full
bool deque_is_full(deque_t* deque) {
  // to do
}

// Add an item at the front
bool deque_insert_front(deque_t* deque, int value) {
  // to do
}

// Add an item at the rear
bool deque_insert_last(deque_t* deque, int value) {
  // to do
}

// Delete an item from the front
bool deque_delete_front(deque_t* deque) {
  // to do
}

// Delete an item from the rear
bool deque_delete_last(deque_t* deque) {
  // to do
}

// Get the front item
int deque_get_front(deque_t* deque) {
  // to do
}

// Get the rear item
int deque_get_rear(deque_t* deque) {
  // to do
}

// Free the deque
void deque_free(deque_t* deque) {
  // to do
}

int main() {
  deque_t* deque = deque_create(3);  // Size 3

  printf("Insert Last 1: %d\n", deque_insert_last(deque, 1));    // returns true
  printf("Insert Last 2: %d\n", deque_insert_last(deque, 2));    // returns true
  printf("Insert Front 3: %d\n", deque_insert_front(deque, 3));  // returns true
  printf("Insert Front 4: %d\n",
         deque_insert_front(deque, 4));  // returns false, queue is full

  printf("Get Rear: %d\n", deque_get_rear(deque));  // returns 2
  printf("Is Full: %d\n", deque_is_full(deque));    // returns true

  printf("Delete Last: %d\n", deque_delete_last(deque));         // returns true
  printf("Insert Front 4: %d\n", deque_insert_front(deque, 4));  // returns true
  printf("Get Front: %d\n", deque_get_front(deque));             // returns 4

  deque_free(deque);  // Free the deque
  return 0;
}