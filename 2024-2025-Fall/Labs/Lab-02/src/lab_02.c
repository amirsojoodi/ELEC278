#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Do not change: define a singly linked list node
struct Node {
  int val;
  struct Node* next;
};

// Function to create a new node
void push(struct Node** head_ref, int new_val) {
  // to do: push a new node with new_val to the beginning (head)
  // of the linked list

  // update head_ref to point to new node
}

// Function to print the singly linked list
void printList(struct Node* head) {
  // to do: complete

  // print NULL when the linked list ends
  printf("NULL\n");
}

// Function to reverse a singly linked list
struct Node* reverseList(struct Node* head) {
  // to do: complete

  return;  // return new head of the reversed list
}

// Function to detect if there is a cycle in the linked list using Floyd's Cycle-Finding Algorithm
bool hasCycle(struct Node* head) {
  // to do: complete

  return;
}

// Function to check if the linked list is a palindrome
bool isPalindrome(struct Node* head) {
  // to do: complete

  return;
}

// Test cases
int main() {
  printf("Test case 1.\n");

  // Create a singly linked list: 5 -> 10 -> 15 -> 20
  // Start with an empty list
  struct Node* head = NULL;

  // Use the push function to add elements to the list
  int arr[4] = {20, 15, 10, 5};
  for (int i = 0; i < 4; i++) {
    push(&head, arr[i]);
  }

  // Print the original list
  printf("Original list: ");
  printList(head);

  // Check if the list is a palindrome
  if (isPalindrome(head)) {
    printf("The list is a palindrome.\n");
  } else {
    printf("The list is not a palindrome.\n");
  }

  // Reverse the list
  head = reverseList(head);
  printf("Reversed list: ");
  printList(head);

  // Check for a cycle (expecting no cycle)
  if (hasCycle(head)) {
    printf("The list has a cycle.\n");
  } else {
    printf("The list does not have a cycle.\n");
  }

  // Creating a cycle for testing
  head->next->next->next = head->next;  // Introduce a cycle

  // Check for a cycle again
  if (hasCycle(head)) {
    printf("The list has a cycle.\n");
  } else {
    printf("The list does not have a cycle.\n");
  }

  return 0;
}
