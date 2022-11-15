#include <stdio.h>
#include <stdlib.h>

// A utility function to search x in arr[] of size n
int search(int arr[], int x, int n) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == x) {
      return i;
    }
  }
  return -1;
}

// Prints postorder traversal from given
// inorder and preorder traversals
void printPostOrder(int in[], int pre[], int n) {
  // The first element in pre[] is always root, search it
  // in in[] to find left and right subtrees
  int root = search(in, pre[0], n);
  // If left subtree is not empty, print left subtree
  if (root != 0) {
    printPostOrder(in, pre + 1, root);
  }
  // If right subtree is not empty, print right subtree
  if (root != n - 1) {
    printPostOrder(in + root + 1, pre + root + 1, n - root - 1);
  }
  // Print root
  printf("%d ", pre[0]);
}

// Driver program to test above functions
int main() {
  int in[] = {4, 2, 1, 7, 5, 8, 3, 6};
  int pre[] = {1, 2, 4, 3, 5, 7, 8, 6};
  int n = sizeof(in) / sizeof(in[0]);
  printf("Postorder traversal of the constructed tree is:\n");
  printPostOrder(in, pre, n);
  return 0;
}