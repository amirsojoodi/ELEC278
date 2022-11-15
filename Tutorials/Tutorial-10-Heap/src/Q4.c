#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct node_st {
  int data;
  struct node_st* left;
  struct node_st* right;
};

typedef struct node_st node_t;

int search(int arr[], int strt, int end, int value);
node_t* newNode(int data);

node_t* buildTree(int in[], int pre[], int inStrt, int inEnd) {
  static int preIndex = 0;
  if (inStrt > inEnd) return NULL;

  /* Pick current node from Preorder traversal using preIndex
  and increment preIndex */
  node_t* tNode = newNode(pre[preIndex++]);

  if (inStrt == inEnd) return tNode;
  int inIndex = search(in, inStrt, inEnd, tNode->data);

  tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
  tNode->right = buildTree(in, pre, inIndex + 1, inEnd);

  return tNode;
}

int search(int arr[], int strt, int end, int value) {
  int i;
  for (i = strt; i <= end; i++) {
    if (arr[i] == value) return i;
  }
}

node_t* newNode(int data) {
  node_t* node = (node_t*)malloc(sizeof(node_t));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return (node);
}

void printInorder(node_t* node) {
  if (node == NULL) return;

  /* first recur on left child */
  printInorder(node->left);
  /* then print the data of node */
  printf("%d ", node->data);
  /* now recur on right child */
  printInorder(node->right);
}
int size(node_t* root) {
  if (root == NULL) {
    return 0;
  }

  return 1 + size(root->left) + size(root->right);
}

bool isHeap(node_t* root, int i, int n) {
  // base case
  if (root == NULL) {
    return true;
  }

  // not complete binary tree: out of valid index range
  if (i >= n) {
    return false;
  }

  // current node has a higher value than its left or right child
  if ((root->left && root->left->data <= root->data) ||
      (root->right && root->right->data <= root->data)) {
    return false;
  }

  return isHeap(root->left, 2 * i + 1, n) && isHeap(root->right, 2 * i + 2, n);
}

// Function to check if a given binary tree is a min-heap or not
bool isHeapo(node_t* root) {
  int i = 0;
  return isHeap(root, i, size(root));
}

int main() {
  /*
  int n;
  printf("Input the number of tree element:\n");
  scanf("%d", &n);
  int* in= (int*)malloc(n * sizeof(int));
  int* pre= (int*)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
      printf("Input the %d item in the tree, inorder traverse:", i);
      int temp;
      scanf("%d", &temp);
      in[i] = temp;
  }

  for (int t = 0; t < n; t++) {
      printf("Input the %d item in the tree, preorder traverse:", t);
      int temp1;
      scanf("%d", &temp1);
      pre[t] = temp1;
  }
  node_t* root = buildTree(in, pre, 0, n - 1);
*/
  int in[] = {5, 3, 6, 2, 8, 4, 10};
  int pre[] = {2, 3, 5, 6, 4, 8, 10};
  int len = sizeof(in) / sizeof(in[0]);
  node_t* root = buildTree(in, pre, 0, len - 1);

  printf("Inorder traversal of the constructed tree is \n");
  printInorder(root);

  if (isHeapo(root)) {
    printf("\nGiven binary tree is a Heap\n");
  } else {
    printf("\nGiven binary tree is not a Heap\n");
  }
  return 0;
}