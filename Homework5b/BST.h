#pragma once
#include <iostream>

template<class T>
class BST {
public:
    struct Node {
        Node* left;
        Node* right;
        T value;

        Node(T v) : left(nullptr), right(nullptr), value(v) {}
    };

    BST() : root(nullptr), treeSize(0) {}

    ~BST() {
        clear();
    }

    const Node* getRootNode() const {
        return root;
    }

    bool insert(T item) {
        if (!root) {
            root = new Node(item);
            ++treeSize;
            return true;
        }
        return insertHelper(root, item);
    }

    bool remove(T item) {
        if (!root) return false;
        bool removed;
        root = removeHelper(root, item, removed);
        if (removed) --treeSize;
        return removed;
    }

    bool contains(T item) const {
        return containsHelper(root, item);
    }

    void clear() {
        clearHelper(root);
        root = nullptr;
        treeSize = 0;
    }

    int size() const {
        return treeSize;
    }

private:
    Node* root;
    int treeSize;

    // Helper function to insert a value into the tree
    bool insertHelper(Node* node, T item) {
        if (item < node->value) {
            if (node->left) {
                return insertHelper(node->left, item);
            } else {
                node->left = new Node(item);
                ++treeSize;
                return true;
            }
        } else if (item > node->value) {
            if (node->right) {
                return insertHelper(node->right, item);
            } else {
                node->right = new Node(item);
                ++treeSize;
                return true;
            }
        }
        return false; // item is already in the tree
    }

    // Helper function to remove a value from the tree
    Node* removeHelper(Node* node, T item, bool& removed) {
        if (!node) {
            removed = false;
            return nullptr;
        }
        if (item < node->value) {
            node->left = removeHelper(node->left, item, removed);
        } else if (item > node->value) {
            node->right = removeHelper(node->right, item, removed);
        } else { // Found the node to remove
            removed = true;
            if (!node->left) {
                Node* rightChild = node->right;
                delete node;
                return rightChild;
            } else if (!node->right) {
                Node* leftChild = node->left;
                delete node;
                return leftChild;
            } else { // Node with two children
                Node* predecessor = findMax(node->left);
                node->value = predecessor->value;
                node->left = removeHelper(node->left, predecessor->value, removed);
            }
        }
        return node;
    }

    // Helper function to check if the tree contains a value
    bool containsHelper(Node* node, T item) const {
        if (!node) return false;
        if (item < node->value) {
            return containsHelper(node->left, item);
        } else if (item > node->value) {
            return containsHelper(node->right, item);
        }
        return true; // Found the item
    }

    // Helper function to clear the tree
    void clearHelper(Node* node) {
        if (!node) return;
        clearHelper(node->left);
        clearHelper(node->right);
        delete node;
    }

    // Helper function to find the maximum value in a subtree
    Node* findMax(Node* node) {
        while (node && node->right) {
            node = node->right;
        }
        return node;
    }
};