#include <stdio.h>
#include <stdlib.h>

// Structure of the tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a new node into the BST
struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return newNode(key);
    }

    if (key < root->data) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }

    return root;
}

// Function to find the minimum value in the BST
struct Node* findMin(struct Node* root) {
    while (root != NULL && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to find the maximum value in the BST
struct Node* findMax(struct Node* root) {
    while (root != NULL && root->right != NULL) {
        root = root->right;
    }
    return root;
}

// Function to search for a key in the BST
int search(struct Node* root, int key) {
    if (root == NULL) {
        return 0; // Key not found
    }

    if (root->data == key) {
        return 1; // Key found
    }

    if (key < root->data) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

// Main function to test the program
int main() {
    struct Node* root = NULL;
    int n, key;

    // Ask the user for the number of keys to insert
    printf("Enter the number of keys to insert: ");
    scanf("%d", &n);

    // Insert keys into the BST
    printf("Enter the keys: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        root = insert(root, key);
    }

    // (a) Minimum key
    struct Node* minNode = findMin(root);
    if (minNode != NULL) {
        printf("Minimum key: %d\n", minNode->data);
    }

    // (b) Maximum key
    struct Node* maxNode = findMax(root);
    if (maxNode != NULL) {
        printf("Maximum key: %d\n", maxNode->data);
    }

    // (c) Search for a given key
    printf("Enter a key to search for: ");
    scanf("%d", &key);
    if (search(root, key)) {
        printf("Key %d found in the BST.\n", key);
    } else {
        printf("Key %d not found in the BST.\n", key);
    }

    return 0;
}
