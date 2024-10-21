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
  struct Node *temp = *head, *prev = NULL;
  if (temp != NULL && temp->data == key) {
    *head = temp->next;
    free(temp);
    return;
  }
  while (temp != NULL && temp->data != key) {
    prev = temp;
    temp = temp->next;
  }
  if (temp == NULL) return;
  prev->next = temp->next;
  free(temp);
}

// Function to search for a node
int searchNode(struct Node* head, int key) {
  struct Node* current = head;
  while (current != NULL) {
    if (current->data == key) return 1;
    current = current->next;
  }
  return 0;
}

// Function to reverse the linked list
void reverseList(struct Node** head) {
  struct Node* prev = NULL;
  struct Node* current = *head;
  struct Node* next = NULL;
  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  *head = prev;
}

// Function to calculate the length of the linked list
int listLength(struct Node* head) {
  int length = 0;
  struct Node* current = head;
  while (current != NULL) {
    length++;
    current = current->next;
  }
  return length;
}

// Function to display the linked list
void printList(struct Node* head) {
  struct Node* current = head;
  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

int main() {
  struct Node* head = NULL;
  insertAtBeginning(&head, 1);
  insertAtBeginning(&head, 2);
  insertAtBeginning(&head, 3);
  printf("Linked list:\n");
  printList(head);
  printf("Length: %d\n", listLength(head));
  printf("Searching for 2: %s\n", searchNode(head, 2) ? "Found" : "Not Found");
  reverseList(&head);
  printf("Reversed linked list:\n");
  printList(head);
  deleteNode(&head, 2);
  printf("Linked list after deletion of 2:\n");
  printList(head);
  return 0;
}