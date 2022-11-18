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

node_t* new_node(int key) {
  node_t* node = (node_t*)malloc(sizeof(node_t));
  node->data = key;
  node->left = node->right = NULL;

  return node;
}

// Function to perform inorder traversal on the tree
void inorder(node_t* root) {
  if (root == NULL) {
    return;
  }

  inorder(root->left);
  printf("%d", root->data);
  inorder(root->right);
}

// Recursive function to insert a key into a BST
node_t* insert(node_t* root, int key) {
  // if the root is null, create a new node and return it
  if (root == NULL) {
    root = new_node(key);
    return root;
  }
  // if the given key is less than the root node, recur for the left subtree
  if (key < root->data) {
    root->left = insert(root->left, key);
  }
  // if the given key is more than the root node, recur for the right subtree
  else {
    root->right = insert(root->right, key);
  }
  return root;
}

// Function to find the k'th largest node in a BST.
// Here, `i` denotes the total number of nodes processed so far
node_t* kth_largest(node_t* root, int* i, int k) {
  // base case
  if (root == NULL) {
    return NULL;
  }
  // search in the right subtree
  node_t* left = kth_largest(root->right, i, k);

  // if k'th largest is found in the left subtree, return it
  if (left) {
    return left;
  }
  // if the current node is k'th largest, return its value
  if (++*i == k) {
    return root;
  }
  // otherwise, search in the left subtree
  return kth_largest(root->left, i, k);
}

// Function to find the k'th largest node in a BST
node_t* find_kth_largest(node_t* root, int k) {
  // maintain index to count the total number of nodes processed so far
  int i = 0;

  // traverse the tree in an inorder fashion and return k'th node
  return kth_largest(root, &i, k);
}

int main() {
  int keys[] = {15, 10, 20, 8, 12, 16, 25};
  int len = sizeof(keys) / sizeof(keys[0]);

  node_t* root = NULL;
  for (int i = 0; i < len; i++) {
    root = insert(root, keys[i]);
  }

  int k = 2;
  node_t* node = find_kth_largest(root, k);

  if (node != NULL) {
    printf("%d", node->data);
  } else {
    printf("Invalid Input");
  }

  return 0;
}
