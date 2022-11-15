#include <stdio.h>
#include <stdlib.h>

struct node_st {
  int key;
  struct node_st *left, *right;
};

typedef struct node_st node_t;

node_t* newNode(int key) {
  node_t* node = (node_t*)malloc(sizeof(node_t));
  node->key = key;
  node->left = node->right = NULL;

  return node;
}

void inorder(node_t* root) {
  if (root == NULL) {
    return;
  }

  inorder(root->left);
  printf("%d ", root->key);
  inorder(root->right);
}

node_t* constructBST(int postorder[], int start, int end) {
  if (start > end) {
    return NULL;
  }

  node_t* node = newNode(postorder[end]);

  int i;
  for (i = end; i >= start; i--) {
    if (postorder[i] < node->key) {
      break;
    }
  }
  node->right = constructBST(postorder, i + 1, end - 1);

  // recursively construct the left subtree
  node->left = constructBST(postorder, start, i);

  // return current node
  return node;
}

int main(void) {
  int postorder[] = {8, 12, 10, 16, 25, 20, 15};
  int n = sizeof(postorder) / sizeof(postorder[0]);

  // construct the BST
  node_t* root = constructBST(postorder, 0, n - 1);

  // print the BST
  printf("Inorder traversal of BST is: \n");

  // inorder on the BST always returns a sorted sequence
  inorder(root);

  return 0;
}