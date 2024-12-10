#pragma once

#include <algorithm>

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
        node->height = 1 + std::max(left_height, right_height);
    }
}

// Perform a left rotation
void promote_left(Node*& root) {
    Node* new_root = root->right;
    root->right = new_root->left;
    new_root->left = root;

    // Update heights of the affected nodes
    update_height(root);
    update_height(new_root);

    // Update root pointer
    root = new_root;
}

// Perform a right rotation
void promote_right(Node*& root) {
    Node* new_root = root->left;
    root->left = new_root->right;
    new_root->right = root;

    // Update heights of the affected nodes
    update_height(root);
    update_height(new_root);

    // Update root pointer
    root = new_root;
}

// Calculate the balance factor of a node
int get_balance_factor(Node* node) {
    if (!node) return 0;
    int left_height = node->left ? node->left->height : 0;
    int right_height = node->right ? node->right->height : 0;
    return left_height - right_height;
}

// Rebalance the tree at the given node
void rebalance(Node*& root) {
    if (!root) return;

    // Update the height of the current node
    update_height(root);

    // Get the balance factor
    int balance_factor = get_balance_factor(root);

    // Left-heavy subtree
    if (balance_factor > 1) {
        // Left-right case
        if (get_balance_factor(root->left) < 0) {
            promote_left(root->left);
        }
        // Left-left case
        promote_right(root);
    }
    // Right-heavy subtree
    else if (balance_factor < -1) {
        // Right-left case
        if (get_balance_factor(root->right) > 0) {
            promote_right(root->right);
        }
        // Right-right case
        promote_left(root);
    }
}