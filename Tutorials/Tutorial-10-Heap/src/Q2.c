/*
  Tutorial 10

  Code provided for ELEC-278 Tutorial at Queen's University

  Adapted from David Athersych
  @author AmirHossein Sojoodi
  @date 2022-11
*/

#include <stdio.h>
#include <stdlib.h>

/* A binary tree node */
struct node_st {
  int key;
  struct node_st *left, *right;
};

typedef struct node_st node_t;

/* Function to find index of value in arr[start...end] */
int search(int* arr, int strt, int end, int value) {
  for (int i = strt; i <= end; i++)
    if (arr[i] == value) return i;
  return -1;
}

// n is size of *level, m is size of in[] and m < n. This
// function extracts keys from *level which are present in
// in[].  The order of extracted keys must be maintained
int* extract_keys(int* in, int* level, int m, int n) {
  int* new_level = (int*)malloc((n + 1) * sizeof(int));
  int j = 0;
  for (int i = 0; i < n; i++)
    if (search(in, 0, m - 1, level[i]) != -1) new_level[j] = level[i], j++;
  return new_level;
}

/* function that allocates a new node with the given key  */
node_t* new_node(int key) {
  node_t* node = (node_t*)malloc(sizeof(node_t));
  node->key = key;
  node->left = NULL;
  node->right = NULL;

  return (node);
}

/* Recursive function to construct binary tree of size n
   from Inorder traversal in[] and Level Order traversal
   *level. in_start and in_end are start and end indexes of
   array in[] Initial values of in_start and in_end should be 0
   and n -1. The function doesn't do any error checking for
   cases where inorder and levelorder do not form a tree */
node_t* build_tree(int* in, int* level, int in_start, int in_end, int n) {
  // If start index is more than the end index
  if (in_start > in_end) return NULL;

  /* The first node in level order traversal is root */
  node_t* root = new_node(level[0]);

  /* If this node has no children then return */
  if (in_start == in_end) return root;

  /* Else find the index of this node in Inorder traversal
   */
  int in_index = search(in, in_start, in_end, root->key);

  // Extract left subtree keys from level order traversal
  int* llevel = extract_keys(in, level, in_index, n);

  // Extract right subtree keys from level order traversal
  int* rlevel = extract_keys(in + in_index + 1, level, n - 1, n);

  /* construct left and right subtrees */
  root->left = build_tree(in, llevel, in_start, in_index - 1, in_index - in_start);
  root->right = build_tree(in, rlevel, in_index + 1, in_end, in_end - in_index);

  // Free memory to avoid memory leak
  free(llevel);
  free(rlevel);

  return root;
}

/* utility function to print inorder traversal of binary
 * tree */
void print_inorder(node_t* node) {
  if (node == NULL) {
    return;
  }
  print_inorder(node->left);
  printf("%d ", node->key);
  print_inorder(node->right);
}

/* Driver program to test above functions */
int main() {
  int in[] = {4, 2, 5, 1, 6, 3, 7};
  int level[] = {1, 2, 3, 4, 5, 6, 7};
  int n = sizeof(in) / sizeof(in[0]);
  node_t* root = build_tree(in, level, 0, n - 1, n);

  /* Let us test the built tree by printing Inorder
   * traversal */
  printf("Inorder traversal of the constructed tree is:\n");
  print_inorder(root);

  return 0;
}