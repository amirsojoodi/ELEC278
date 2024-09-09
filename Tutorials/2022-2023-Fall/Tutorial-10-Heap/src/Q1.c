/*
  Tutorial 10

  Code provided for ELEC-278 Tutorial at Queen's University

  Adapted from David Athersych
  @author AmirHossein Sojoodi
  @date 2022-11
*/

#include <stdio.h>
#include <stdlib.h>

struct node_st {
  int data;
  struct node_st* left;
  struct node_st* right;
};

typedef struct node_st node_t;

/* Prototypes for utility functions */
int search(int* arr, int strt, int end, int value);
node_t* new_node(int data);

/* Recursive function to construct binary of size len from
   Inorder traversal in[] and Preorder traversal pre[].  Initial values
   of in_start and in_end should be 0 and len -1.  The function doesn't
   do any error checking for cases where inorder and preorder
   do not form a tree */
node_t* build_tree(int* in, int* pre, int in_start, int in_end) {
  static int pre_index = 0;
  if (in_start > in_end) return NULL;

  /* Pick current node from Preorder traversal using pre_index
  and increment pre_index */
  node_t* tmp_node = new_node(pre[pre_index++]);

  /* If this node has no children then return */
  if (in_start == in_end) return tmp_node;
  /* Else find the index of this node in Inorder traversal */
  int in_index = search(in, in_start, in_end, tmp_node->data);
  /* Using index in Inorder traversal, construct left and
   right subtress */
  tmp_node->left = build_tree(in, pre, in_start, in_index - 1);
  tmp_node->right = build_tree(in, pre, in_index + 1, in_end);

  return tmp_node;
}

/* Function to find index of value in arr[start...end]
   The function assumes that value is present in in[] */
int search(int* arr, int strt, int end, int value) {
  int i;
  for (i = strt; i <= end; i++) {
    if (arr[i] == value) return i;
  }
}

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
node_t* new_node(int data) {
  node_t* node = (node_t*)malloc(sizeof(node_t));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return (node);
}

/* This function is here just to test build_tree() */
void print_inorder(node_t* node) {
  if (node == NULL) return;

  /* first recur on left child */
  print_inorder(node->left);
  /* then print the data of node */
  printf("%d ", node->data);
  /* now recur on right child */
  print_inorder(node->right);
}
void print_preorder(node_t* node) {
  if (node == NULL) {
    return;
  }
  printf("%d ", node->data);
  print_preorder(node->left);
  print_preorder(node->right);
}

/* Driver program to test above functions */
int main() {
  int in[] = {4, 2, 1, 7, 5, 8, 3, 6};
  int pre[] = {1, 2, 4, 3, 5, 7, 8, 6};
  int len = sizeof(in) / sizeof(in[0]);
  node_t* root = build_tree(in, pre, 0, len - 1);

  /* Let us test the built tree by printing Inorder traversal */
  printf("Inorder traversal of the constructed tree is \n");
  print_inorder(root);
  printf("\nPreorder traversal of the constructed tree is \n");
  print_preorder(root);
}