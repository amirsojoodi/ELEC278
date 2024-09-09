/*
  Tutorial 8 - Trees

  Code provided for ELEC-278 Tutorial at Queen's University

  Adapted from David Athersych and programiz.com
  @author AmirHossein Sojoodi
  @date 2022-10
*/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct node_t {
  int key;
  struct node_t* left;
  struct node_t* right;
};

typedef int bool;
typedef struct node_t node;

// Inorder traversal
void inorder_traverse(node* root) {
  if (root == NULL) {
    return;
  }
  inorder_traverse(root->left);
  printf("%d ->", root->key);
  inorder_traverse(root->right);
}

// Preorder traversal
void preorder_traverse(node* root) {
  if (root == NULL) {
    return;
  }
  printf("%d ->", root->key);
  preorder_traverse(root->left);
  preorder_traverse(root->right);
}

// Postorder traversal
void postorder_traverse(node* root) {
  if (root == NULL) {
    return;
  }
  postorder_traverse(root->left);
  postorder_traverse(root->right);
  printf("%d ->", root->key);
}

bool is_full_binary_tree(node* root) {
  // Checking tree emptiness
  if (root == NULL) return TRUE;

  // Checking the presence of children
  if (root->left == NULL && root->right == NULL) return TRUE;

  if ((root->left) && (root->right))
    return (is_full_binary_tree(root->left) && is_full_binary_tree(root->right));

  return FALSE;
}

// Check if the tree is perfect
bool is_perfect(node* root, int d, int level) {
  // Check if the tree is empty
  if (root == NULL) return TRUE;

  // Check the presence of children
  if (root->left == NULL && root->right == NULL) {
    return (d == level + 1);
  }

  if (root->left == NULL || root->right == NULL) {
    return FALSE;
  }

  return is_perfect(root->left, d, level + 1) && is_perfect(root->right, d, level + 1);
}

// Calculate the depth
int depth_left_side(node* root) {
  if (root == NULL) {
    return 0;
  }
  return depth_left_side(root->left) + 1;
}

// Wrapper function
bool is_perfect_wrapper(node* root) {
  int d = depth_left_side(root);
  return is_perfect(root, d, 0);
}

// Count the number of nodes
int get_node_count(node* root) {
  if (root == NULL) {
    return 0;
  }
  return (1 + get_node_count(root->left) + get_node_count(root->right));
}

// Check if the tree is a complete binary tree
bool is_complete(node* root, int index, int node_count) {
  // Check if the tree is complete
  if (root == NULL) {
    return TRUE;
  }
  if (index >= node_count) {
    return FALSE;
  }
  return (is_complete(root->left, 2 * index + 1, node_count) &&
          is_complete(root->right, 2 * index + 2, node_count));
}

bool is_balanced(node* root, int* height) {
  // Check for emptiness
  int left_height = 0, right_height = 0;
  int left_balanced = FALSE, right_balanced = FALSE;

  if (root == NULL) {
    *height = 0;
    return TRUE;
  }

  left_balanced = is_balanced(root->left, &left_height);
  right_balanced = is_balanced(root->right, &right_height);

  *height = (left_height > right_height ? left_height : right_height) + 1;

  if ((left_height - right_height >= 2) || (right_height - left_height >= 2)) {
    return FALSE;
  } else {
    return left_balanced && right_balanced;
  }
}

// Create a new Node
node* create_node(int value) {
  node* newNode = malloc(sizeof(node));
  newNode->key = value;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

// Insert on the left of the node
node* insert_left(node* root, int value) {
  root->left = create_node(value);
  return root->left;
}

// Insert on the right of the node
node* insert_right(node* root, int value) {
  root->right = create_node(value);
  return root->right;
}

// Recursive function to insert a key into a BST
node* insert(node* root, int value) {
  // if the root is null, create a new node and return it
  if (root == NULL) {
    return create_node(value);
  }

  // if the given key is less than the root node,
  // insert it in the left subtree
  if (value < root->key) {
    root->left = insert(root->left, value);
  }
  // if the given key is more than the root node,
  // insert it in the right subtree
  else {
    root->right = insert(root->right, value);
  }

  return root;
}

// Find the inorder successor
node* next_min_node(node* root) {
  node* current = root;
  // Find the leftmost leaf
  while (current != NULL && current->left != NULL) {
    current = current->left;
  }
  return current;
}

// Deleting a node
node* delete_node(node* root, int key) {
  // Return if the tree is empty
  if (root == NULL) return root;

  // Find the node to be deleted
  if (key < root->key)
    root->left = delete_node(root->left, key);
  else if (key > root->key)
    root->right = delete_node(root->right, key);
  else {
    // If the node is with only one child or no child
    if (root->left == NULL) {
      node* temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      node* temp = root->left;
      free(root);
      return temp;
    }
    // If the node has two children
    node* temp = next_min_node(root->right);
    // Place the inorder successor in position of the node to be deleted
    root->key = temp->key;
    // Delete the inorder successor
    root->right = delete_node(root->right, temp->key);
  }
  return root;
}

int main() {
  node* root = create_node(1);
  insert_left(root, 2);
  insert_right(root, 3);
  insert_left(root->left, 4);

  printf("Inorder traversal: \n");
  inorder_traverse(root);

  printf("\nPreorder traversal: \n");
  preorder_traverse(root);

  printf("\nPostorder traversal: \n");
  postorder_traverse(root);

  if (is_full_binary_tree(root)) {
    printf("\nThe tree is a full binary tree!\n");
  } else {
    printf("\nThe tree is not a full binary tree!\n");
  }

  if (is_perfect_wrapper(root)) {
    printf("\nThe tree is a perfect binary tree!\n");
  } else {
    printf("\nThe tree is not a perfect binary tree!\n");
  }

  int node_count = get_node_count(root);
  int index = 0;

  if (is_complete(root, index, node_count)) {
    printf("\nThe tree is a complete binary tree!\n");
  } else {
    printf("\nThe tree is not a complete binary tree!\n");
  }

  int height = 0;
  if (is_balanced(root, &height)) {
    printf("\nThe tree is balanced!\n");
  } else {
    printf("\nThe tree is not balanced!\n");
  }
}
