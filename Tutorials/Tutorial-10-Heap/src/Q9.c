/*
  Tutorial 10

  Code provided for ELEC-278 Tutorial at Queen's University

  Adapted from David Athersych
  @author AmirHossein Sojoodi
  @date 2022-11
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct node_st {
  int data;
  struct node_st* next;
};

typedef struct node_st node_t;

node_t* new_node(int key) {
  node_t* node = (node_t*)malloc(sizeof(node_t));
  node->data = key;
  node->next = NULL;

  return node;
}

/* Function to print nodes in
   a given linked list */
void print_list(node_t* node) {
  while (node != NULL) {
    printf("%d ", node->data);
    node = node->next;
  }
}

// The main function that
// takes an array of lists
// arr[0..last] and generates
// the sorted output
node_t* merge_k_lists(node_t* arr[], int last) {
  // Traverse form second list to last
  for (int i = 1; i <= last; i++) {
    while (true) {
      // head of both the lists,
      // 0 and ith list.
      node_t *head_0 = arr[0], *head_i = arr[i];

      // Break if list ended
      if (head_i == NULL) break;

      // Smaller than first element
      if (head_0->data >= head_i->data) {
        arr[i] = head_i->next;
        head_i->next = head_0;
        arr[0] = head_i;
      } else
        // Traverse the first list
        while (head_0->next != NULL) {
          // Smaller than next element
          if (head_0->next->data >= head_i->data) {
            arr[i] = head_i->next;
            head_i->next = head_0->next;
            head_0->next = head_i;
            break;
          }
          // go to next node
          head_0 = head_0->next;

          // if last node
          if (head_0->next == NULL) {
            arr[i] = head_i->next;
            head_i->next = NULL;
            head_0->next = head_i;
            head_0->next->next = NULL;
            break;
          }
        }
    }
  }

  return arr[0];
}

// Driver program to test
// above functions
int main() {
  // Number of linked lists

  // Number of elements in each list
  int n = 4;
  int k = 3;

  // an array of pointers storing the
  // head nodes of the linked lists
  node_t* arr[3];

  arr[0] = new_node(1);
  arr[0]->next = new_node(5);
  arr[0]->next->next = new_node(7);
  arr[0]->next->next->next = new_node(7);

  arr[1] = new_node(2);
  arr[1]->next = new_node(3);
  arr[1]->next->next = new_node(6);
  arr[1]->next->next->next = new_node(9);

  arr[2] = new_node(4);
  arr[2]->next = new_node(8);
  arr[2]->next->next = new_node(10);

  // Merge all lists
  node_t* head = merge_k_lists(arr, k - 1);

  print_list(head);

  return 0;
}