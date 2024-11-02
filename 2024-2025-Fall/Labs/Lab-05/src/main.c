#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition of the tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Helper function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// HEIGHT OF TREE
// Function to calculate the height of the tree
int getHeight(Node* root) {
    // to do: complete
}

// BALANCED TREE?
// Function to check if the tree is height balanced
bool isHeightBalanced(Node* root) {
    // to do: complete
}

// ZIG-ZAG LEVEL-ORDER OF A TREE

// Function to print zigzag level order traversal
void printZigzagLevelOrder(Node* root) {
    // to do: complete
}

// TREASURE LOOT
// Function to return the maximum amount of money the thief can rob
int rob(Node* root) {
    // to do: complete
}


void freeTree(Node* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->left->left->left = createNode(6);

    printf("Height of the tree: %d\n", getHeight(root));

    if (isHeightBalanced(root)) {
        printf("The tree is height balanced.\n");
    } else {
        printf("The tree is not height balanced.\n");
    }

    freeTree(root);

    root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Height of the tree: %d\n", getHeight(root));

    if (isHeightBalanced(root)) {
        printf("The tree is height balanced.\n");
    } else {
        printf("The tree is not height balanced.\n");
    }

    printf("Zigzag Level Order Traversal: ");
    printZigzagLevelOrder(root);

    printf("\nMaximum amount of items the looter can loot: %d\n", rob(root));

    freeTree(root);

    return 0;
}
