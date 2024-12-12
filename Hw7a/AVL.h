#pragma once

#include <algorithm>

template<class T>
class AVL {
public:
    struct Node {
        Node* left;
        Node* right;
        T value;
        int height;

        Node(T v) : left(nullptr), right(nullptr), value(v), height(1) {}
    };

    AVL() : root(nullptr), tree_size(0) {}

    ~AVL() {
        clear();
    }

    const Node* getRootNode() const {
        return root;
    }

    bool insert(T item) {
        if (!contains(item)) {
            root = insertRecursive(root, item);
            ++tree_size;
            return true;
        }
        return false;
    }

    bool remove(T item) {
        if (contains(item)) {
            root = removeRecursive(root, item);
            --tree_size;
            return true;
        }
        return false;
    }

    bool contains(T item) const {
        return containsRecursive(root, item);
    }

    void clear() {
        root = clearRecursive(root);
        tree_size = 0;
    }

    int size() const {
        return tree_size;
    }

private:
    Node* root;
    int tree_size;

    // Utility functions for AVL balancing
    int height(Node* node) const {
        return node ? node->height : 0;
    }

    int balanceFactor(Node* node) const {
        return height(node->left) - height(node->right);
    }

    void updateHeight(Node* node) {
        node->height = std::max(height(node->left), height(node->right)) + 1;
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        
        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    Node* rebalance(Node* node) {
        int balance = balanceFactor(node);

        if (balance > 1) {
            if (balanceFactor(node->left) < 0) {
                node->left = rotateLeft(node->left);
            }
            return rotateRight(node);
        }

        if (balance < -1) {
            if (balanceFactor(node->right) > 0) {
                node->right = rotateRight(node->right);
            }
            return rotateLeft(node);
        }

        return node;
    }

    Node* insertRecursive(Node* node, T item) {
        if (!node) return new Node(item);

        if (item < node->value) {
            node->left = insertRecursive(node->left, item);
        } else if (item > node->value) {
            node->right = insertRecursive(node->right, item);
        }

        updateHeight(node);
        return rebalance(node);
    }

    Node* removeRecursive(Node* node, T item) {
        if (!node) return node;

        if (item < node->value) {
            node->left = removeRecursive(node->left, item);
        } else if (item > node->value) {
            node->right = removeRecursive(node->right, item);
        } else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = findMin(node->right);
            node->value = temp->value;
            node->right = removeRecursive(node->right, temp->value);
        }

        updateHeight(node);
        return rebalance(node);
    }

    Node* findMin(Node* node) const {
        while (node->left) {
            node = node->left;
        }
        return node;
    }

    bool containsRecursive(Node* node, T item) const {
        if (!node) return false;

        if (item < node->value) {
            return containsRecursive(node->left, item);
        } else if (item > node->value) {
            return containsRecursive(node->right, item);
        }
        return true;
    }

    Node* clearRecursive(Node* node) {
        if (!node) return nullptr;

        node->left = clearRecursive(node->left);
        node->right = clearRecursive(node->right);
        delete node;
        return nullptr;
    }
};