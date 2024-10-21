#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int newData) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = newData;
  newNode->next = *head;
  *head = newNode;
}

// Function to delete a node
void deleteNode(struct Node** head, int key) {
  // base case
  if (*head == NULL) {
    return;
  }
  // the head of the list
  if ((*head)->data == key) {
    struct Node* tmp = (*head)->next;
    free(*head);
    *head = tmp;
    return;
  }
  // printf("in deleteNode, head->data = %d \n", (*head)->data);
  deleteNode(&((*head)->next), key);
}

// Function to search for a node
int searchNode(struct Node* head, int key) {
  if (head == NULL) {
    return 0;
  }
  if (head->data == key) {
    return 1;
  }
  return searchNode(head->next, key);
}

// Function to reverse the linked list
void reverseList(struct Node** head, struct Node *curr) {
  // base case
  if (curr == NULL) {
    return;
  }
  if (curr->next == NULL) {
    *head = curr;
    return;
  }
  reverseList(head, curr->next);
  curr->next->next = curr;
  curr->next = NULL;
}

// Function to calculate the length of the linked list
int listLength(struct Node* head) {
  // base case
  if (head == NULL) {
    return 0;
  }
  return 1 + listLength(head->next);
}

// Function to display the linked list
void printList(struct Node* head) {
  // Base case
  if (head == NULL) {
    printf("NULL\n");
    return;
  }
  printf("%d -> ", head->data);
  printList(head->next);
}

int main() {
  struct Node* head = NULL;
  insertAtBeginning(&head, 1);
  insertAtBeginning(&head, 2);
  insertAtBeginning(&head, 3);
  insertAtBeginning(&head, 4);
  insertAtBeginning(&head, 5);
  printf("Linked list:\n");
  printList(head);
  printf("Length: %d\n", listLength(head));
  printf("Searching for 2: %s\n", searchNode(head, 2) ? "Found" : "Not Found");
  reverseList(&head, head);
  printf("Reversed linked list:\n");
  printList(head);
  deleteNode(&head, 2);
  printf("Linked list after deletion of 2:\n");
  printList(head);
  return 0;
}