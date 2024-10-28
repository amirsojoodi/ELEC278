#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* left;
  struct Node* right;
} Node;

void printTree(Node* root, int space) {
  if (root == NULL) return;

  space += 10;
  printTree(root->right, space);
  printf("\n");
  for (int i = 10; i < space; i++) {
    printf(" ");
  }
  printf("%d\n", root->data);
  printTree(root->left, space);
}

// Function to create a new node
struct Node* newNode(int data) {
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}

Node* insertIterative(Node* root, int data) {
  Node* new_node = newNode(data);
  if (root == NULL) return new_node;

  Node* current = root;
  Node* parent;
  while (current != NULL) {
    parent = current;
    if (data > current->data) {
      current = current->right;
    } else {
      current = current->left;
    }
  }

  if (parent->data > data) {
    parent->left = new_node;
  } else {
    parent->right = new_node;
  }

  return root;
}

// Recursive function to insert a new node
struct Node* insertRecursive(struct Node* node, int data) {
  if (node == NULL) return newNode(data);
  if (data < node->data)
    node->left = insertRecursive(node->left, data);
  else
    node->right = insertRecursive(node->right, data);
  return node;
}

// Recursive function to find the minimum node
struct Node* findMin(struct Node* node) {
  struct Node* current = node;
  while (current && current->left != NULL) current = current->left;
  return current;
}

Node* findMinRecursive(Node* root) {
  if (root->left == NULL) {
    return root;
  }
  return findMinRecursive(root->left);
}

Node* deleteIterative(Node* root, int key) {
  if (root == NULL) {
    return root;
  }

  Node* current = root;
  Node* parent = NULL;
  while (current != NULL) {
    parent = current;
    if (current->data > key) {
      current = current->right;
    } else if (current->data < key) {
      current = current->left;
    } else {
      break;
    }
  }

  // we found the node to be deleted
  if (current == NULL) {
    return root;
  }

  // handle leafs
  if (current->right == NULL && current->left == NULL) {
    free(current);
    if (parent->data > key) {
      parent->left = NULL;
    } else {
      parent->right = NULL;
    }
    return root;
  }

  // handle nodes with only one child
  if (current->right == NULL || current->left == NULL) {
    if (current->right == NULL) {
      if (parent->data > key) {
        parent->left = current->left;
      } else {
        parent->right = current->left;
      }
    } else {
      if (parent->data > key) {
        parent->left = current->right;
      } else {
        parent->right = current->right;
      }
    }
    free(current);
    return root;
  }

  //TODO: incomplete, see the tutorial solutions
}

// Recursive function to delete a node
struct Node* deleteRecursive(struct Node* root, int key) {
  if (root == NULL) return root;
  if (key < root->data)
    root->left = deleteRecursive(root->left, key);
  else if (key > root->data)
    root->right = deleteRecursive(root->right, key);
  else {
    if (root->left == NULL) {
      struct Node* temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct Node* temp = root->left;
      free(root);
      return temp;
    }
    struct Node* temp = findMin(root->right);
    root->data = temp->data;
    root->right = deleteRecursive(root->right, temp->data);
  }
  return root;
}

// Function to print BST nodes in inorder traversal
void inorder(struct Node* root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

int main() {
  struct Node* root = NULL;
  root = insertIterative(root, 50);
  printTree(root, 0);
  printf("===============================\n");

  root = insertIterative(root, 30);
  printTree(root, 0);
  printf("===============================\n");

  root = insertIterative(root, 20);
  printTree(root, 0);
  printf("===============================\n");

  root = insertIterative(root, 40);
  printTree(root, 0);
  printf("===============================\n");

  root = insertIterative(root, 70);
  printTree(root, 0);
  printf("===============================\n");

  root = insertIterative(root, 60);
  printTree(root, 0);
  printf("===============================\n");

  root = insertIterative(root, 80);
  printTree(root, 0);
  printf("===============================\n");

  printf("Inorder traversal of the BST: ");
  inorder(root);
  printf("\n");

  root = deleteRecursive(root, 20);
  root = deleteRecursive(root, 30);
  root = deleteRecursive(root, 50);

  printf("Inorder traversal after deletion: ");
  inorder(root);
  printf("\n");

  return 0;
}