#pragma once

#include <algorithm> // for std::max

struct Node {
    Node* left;
    Node* right;
    int value;
    int height;

    Node(int v) : left(nullptr), right(nullptr), value(v), height(1) {}
};

// Helper function to update the height of a node
void update_height(Node* node) {
    if (node) {
        int left_height = node->left ? node->left->height : 0;
        int right_height = node->right ? node->right->height : 0;
        node->height = std::max(left_height, right_height) + 1;
    }
}

// Perform a left rotation
void promote_left(Node*& root) {
    if (!root || !root->right) return; // No right child to promote

    Node* new_root = root->right;
    root->right = new_root->left;
    new_root->left = root;

    // Update heights
    update_height(root);
    update_height(new_root);

    // Update root pointer
    root = new_root;
}

// Perform a right rotation
void promote_right(Node*& root) {
    if (!root || !root->left) return; // No left child to promote

    Node* new_root = root->left;
    root->left = new_root->right;
    new_root->right = root;

    // Update heights
    update_height(root);
    update_height(new_root);

    // Update root pointer
    root = new_root;
}

// Rebalance the tree
void rebalance(Node*& root) {
    if (!root) return;

    // Update the height of the current node
    update_height(root);

    // Calculate the balance factor
    int left_height = root->left ? root->left->height : 0;
    int right_height = root->right ? root->right->height : 0;
    int balance = left_height - right_height;

    // Left-heavy
    if (balance > 1) {
        int left_child_balance = (root->left->left ? root->left->left->height : 0) - 
                                 (root->left->right ? root->left->right->height : 0);
        if (left_child_balance < 0) {
            // Left-Right case
            promote_left(root->left);
        }
        // Left-Left case
        promote_right(root);
    }
    // Right-heavy
    else if (balance < -1) {
        int right_child_balance = (root->right->left ? root->right->left->height : 0) - 
                                  (root->right->right ? root->right->right->height : 0);
        if (right_child_balance > 0) {
            // Right-Left case
            promote_right(root->right);
        }
        // Right-Right case
        promote_left(root);
    }
}