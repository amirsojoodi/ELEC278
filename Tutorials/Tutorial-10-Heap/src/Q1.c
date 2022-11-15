#include <stdio.h>
#include <stdlib.h>

struct node_st {
  int data;
  struct node_st* left;
  struct node_st* right;
};

typedef struct node_st node_t;

/* Prototypes for utility functions */
int search(int arr[], int strt, int end, int value);
node_t* newNode(int data);

/* Recursive function to construct binary of size len from
   Inorder traversal in[] and Preorder traversal pre[].  Initial values
   of inStrt and inEnd should be 0 and len -1.  The function doesn't
   do any error checking for cases where inorder and preorder
   do not form a tree */
node_t* buildTree(int in[], int pre[], int inStrt, int inEnd) {
  static int preIndex = 0;
  if (inStrt > inEnd) return NULL;

  /* Pick current node from Preorder traversal using preIndex
  and increment preIndex */
  node_t* tNode = newNode(pre[preIndex++]);

  /* If this node has no children then return */
  if (inStrt == inEnd) return tNode;
  /* Else find the index of this node in Inorder traversal */
  int inIndex = search(in, inStrt, inEnd, tNode->data);
  /* Using index in Inorder traversal, construct left and
   right subtress */
  tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
  tNode->right = buildTree(in, pre, inIndex + 1, inEnd);

  return tNode;
}

/* Function to find index of value in arr[start...end]
   The function assumes that value is present in in[] */
int search(int arr[], int strt, int end, int value) {
  int i;
  for (i = strt; i <= end; i++) {
    if (arr[i] == value) return i;
  }
}

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
node_t* newNode(int data) {
  node_t* node = (node_t*)malloc(sizeof(node_t));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return (node);
}

/* This function is here just to test buildTree() */
void printInorder(node_t* node) {
  if (node == NULL) return;

  /* first recur on left child */
  printInorder(node->left);
  /* then print the data of node */
  printf("%d ", node->data);
  /* now recur on right child */
  printInorder(node->right);
}
void printPreorder(node_t* node) {
  if (node == NULL) {
    return;
  }
  printf("%d ", node->data);
  printPreorder(node->left);
  printPreorder(node->right);
}

/* Driver program to test above functions */
int main() {
  int in[] = {4, 2, 1, 7, 5, 8, 3, 6};
  int pre[] = {1, 2, 4, 3, 5, 7, 8, 6};
  int len = sizeof(in) / sizeof(in[0]);
  node_t* root = buildTree(in, pre, 0, len - 1);

  /* Let us test the built tree by printing Inorder traversal */
  printf("Inorder traversal of the constructed tree is \n");
  printInorder(root);
  printf("\nPreorder traversal of the constructed tree is \n");
  printPreorder(root);
}