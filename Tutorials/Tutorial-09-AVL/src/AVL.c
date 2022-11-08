/*
  Tutorial 9 - AVL Trees

  Code provided for ELEC-278 Tutorial at Queen's University

  Adapted from David Athersych and programiz.com
  @author AmirHossein Sojoodi
  @date 2022-11
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b)) ? (a) : (b)

struct node_st {
  int key;
  struct node_st *left;
  struct node_st *right;
  int height;
};

typedef struct node_st node_t;

int get_height(node_t *node) {
  if (node == NULL)
    return 0;
  return node->height;
}

node_t *new_node(int key) {
  node_t *node = (node_t *)malloc(sizeof(node));
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return (node);
}

node_t *rotate_right(node_t *n) {
  // n_LC : n Left Child
  node_t *n_LC = n->left;
  node_t *n_LC_RC = n_LC->right;

  // Perform rotation
  n_LC->right = n;
  n->left = n_LC_RC;

  // Update heights
  n->height = MAX(get_height(n->left), get_height(n->right)) + 1;
  n_LC->height = MAX(get_height(n_LC->left), get_height(n_LC->right)) + 1;

  // Return new root
  return n_LC;
}

node_t *rotate_left(node_t *n) {
  node_t *n_RC = n->right;
  node_t *n_RC_L = n_RC->left;

  // Perform rotation
  n_RC->left = n;
  n->right = n_RC_L;

  // Update heights
  n->height = MAX(get_height(n->left), get_height(n->right)) + 1;
  n_RC->height = MAX(get_height(n_RC->left), get_height(n_RC->right)) + 1;

  // Return new root
  return n_RC;
}

int get_balance_factor(node_t *node) {
  if (node == NULL)
    return 0;
  return get_height(node->left) - get_height(node->right);
}

node_t *insert(node_t *node, int key) {
  /* 1. Perform the normal BST insertino */
  if (node == NULL)
    return (new_node(key));

  if (key < node->key)
    node->left = insert(node->left, key);
  else if (key > node->key)
    node->right = insert(node->right, key);
  else // Equal keys not allowed
    return node;

  /* 2. Update height of this ancestor node_t */
  node->height = 1 + MAX(get_height(node->left), get_height(node->right));

  /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
  int balance = get_balance_factor(node);

  // If this node becomes unbalanced, then there are 4 cases

  // Left Left Case
  if (balance > 1 && key < node->left->key)
    return rotate_right(node);

  // Right Right Case
  if (balance < -1 && key > node->right->key)
    return rotate_left(node);

  // Left Right Case
  if (balance > 1 && key > node->left->key) {
    node->left = rotate_left(node->left);
    return rotate_right(node);
  }

  // Right Left Case
  if (balance < -1 && key < node->right->key) {
    node->right = rotate_right(node->right);
    return rotate_left(node);
  }

  /* return the (unchanged) node pointer */
  return node;
}

/* Given a non-empty binary search tree, return the
node with minimum key value found in that tree.
Note that the entire tree does not need to be
searched. */
node_t *min_value_node(node_t *node) {
  node_t *current = node;

  /* loop down to find the leftmost leaf */
  while (current->left != NULL)
    current = current->left;

  return current;
}

// Recursive function to delete a node with given key
// from subtree with given root. It returns root of
// the modified subtree.
node_t *delete_node(node_t *root, int key) {
  // STEP 1: PERFORM STANDARD BST DELETE

  if (root == NULL)
    return root;

  // If the key to be deleted is smaller than the
  // root's key, then it lies in left subtree
  if (key < root->key)
    root->left = delete_node(root->left, key);

  // If the key to be deleted is greater than the
  // root's key, then it lies in right subtree
  else if (key > root->key)
    root->right = delete_node(root->right, key);

  // if key is same as root's key, then This is
  // the node to be deleted
  else {
    // node with only one child or no child
    if ((root->left == NULL) || (root->right == NULL)) {
      node_t *temp = root->left ? root->left : root->right;

      // No child case
      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else           // One child case
        *root = *temp; // Copy the contents of
                       // the non-empty child
      free(temp);
    } else {
      // node with two children: Get the inorder
      // successor (smallest in the right subtree)
      node_t *temp = min_value_node(root->right);

      // Copy the inorder successor's data to this node
      root->key = temp->key;

      // Delete the inorder successor
      root->right = delete_node(root->right, temp->key);
    }
  }

  // If the tree had only one node then return
  if (root == NULL)
    return root;

  // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
  root->height = 1 + MAX(get_height(root->left), get_height(root->right));

  // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
  // check whether this node became unbalanced)
  int balance = get_balance_factor(root);

  // If this node becomes unbalanced, then there are 4 cases

  // Left Left Case
  if (balance > 1 && get_balance_factor(root->left) >= 0)
    return rotate_right(root);

  // Left Right Case
  if (balance > 1 && get_balance_factor(root->left) < 0) {
    root->left = rotate_left(root->left);
    return rotate_right(root);
  }

  // Right Right Case
  if (balance < -1 && get_balance_factor(root->right) <= 0)
    return rotate_left(root);

  // Right Left Case
  if (balance < -1 && get_balance_factor(root->right) > 0) {
    root->right = rotate_right(root->right);
    return rotate_left(root);
  }

  return root;
}

// A utility function to print preorder traversal of
// the tree.
// The function also prints height of every node
void pre_order_traverse(node_t *root) {
  if (root != NULL) {
    printf("%d ", root->key);
    pre_order_traverse(root->left);
    pre_order_traverse(root->right);
  }
}

/* Driver program to test above function*/
int main() {
  node_t *root = NULL;

  /* Constructing tree given in the above figure */
  root = insert(root, 9);
  root = insert(root, 5);
  root = insert(root, 10);
  root = insert(root, 0);
  root = insert(root, 6);
  root = insert(root, 11);
  root = insert(root, -1);
  root = insert(root, 1);
  root = insert(root, 2);

  /* The constructed AVL Tree would be
           9
          / \
          1 10
         / \	\
         0 5	 11
        / / \
       -1 2 6
  */

  printf("Preorder traversal of the constructed AVL tree is \n");
  pre_order_traverse(root);

  root = delete_node(root, 10);

  /* The AVL Tree after deletion of 10
          1
         / \
        0   9
       /	 / \
     -1   5  11
         / \
         2 6
  */

  printf("\nPreorder traversal after deletion of 10 \n");
  pre_order_traverse(root);

  return 0;
}
