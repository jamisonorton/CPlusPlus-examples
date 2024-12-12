#pragma once

#include <algorithm>

struct Node {
    Node* left;
    Node* right;
    int value;
    int height;

    Node(int v) : left(nullptr), right(nullptr), value(v), height(1) {}
};

// Helper function to get the height of a node
int get_height(Node* node) {
    return node ? node->height : 0;
}

// Function to update the height of a node based on its children
void update_height(Node* node) {
    if (node) {
        node->height = std::max(get_height(node->left), get_height(node->right)) + 1;
    }
}

// Function to perform a left rotation on the tree
void promote_left(Node*& root) {
    if (root == nullptr || root->right == nullptr) {
        return;  // No need to rotate if root is null or there is no right child
    }

    Node* new_root = root->right;  // The new root will be the right child of the current root
    root->right = new_root->left;  // The right child's left subtree becomes the old root's right subtree
    new_root->left = root;  // The old root becomes the left child of the new root

    // Update the heights of the nodes after rotation
    update_height(root);
    update_height(new_root);

    root = new_root;  // Set the new root of the subtree
}

// Function to perform a right rotation on the tree
void promote_right(Node*& root) {
    if (root == nullptr || root->left == nullptr) {
        return;  // No need to rotate if root is null or there is no left child
    }

    Node* new_root = root->left;  // The new root will be the left child of the current root
    root->left = new_root->right;  // The left child's right subtree becomes the old root's left subtree
    new_root->right = root;  // The old root becomes the right child of the new root

    // Update the heights of the nodes after rotation
    update_height(root);
    update_height(new_root);

    root = new_root;  // Set the new root of the subtree
}

// Helper function to get the balance factor of a node
int get_balance(Node* node) {
    return get_height(node->left) - get_height(node->right);
}

// Function to rebalance the tree after insertion or deletion
void rebalance(Node*& root) {
    if (root == nullptr) return;

    // Get the balance factor of the current node
    int balance = get_balance(root);

    // Left heavy subtree
    if (balance > 1) {
        // Left-Right case: Left child is right-heavy
        if (get_balance(root->left) < 0) {
            promote_left(root->left);  // Perform a left rotation on the left child
        }
        promote_right(root);  // Perform a right rotation on the root
    }
    // Right heavy subtree
    else if (balance < -1) {
        // Right-Left case: Right child is left-heavy
        if (get_balance(root->right) > 0) {
            promote_right(root->right);  // Perform a right rotation on the right child
        }
        promote_left(root);  // Perform a left rotation on the root
    }

    // Update the height of the root after rebalancing
    update_height(root);
}