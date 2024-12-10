#pragma once

template <class T>
class SLList {
public:
    struct Node {
        Node* next;
        T value;

        Node(T v) : next(nullptr), value(v) {}
    };

    // Default constructor that initializes an empty list
    SLList() : head(nullptr), list_size(0) {}

    // Destructor that clears the list
    ~SLList() {
        clear();
    }

    // Returns a pointer to the head node
    const Node* get_head() const {
        return head;
    }

    // Adds a new node with the given item to the end of the list
    void push_back(T item) {
        Node* new_node = new Node(item);
        if (!head) {
            head = new_node;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = new_node;
        }
        ++list_size;
    }

    // Removes the last node in the list
    void pop_back() {
        if (head) {
            if (!head->next) {
                delete head;
                head = nullptr;
            } else {
                Node* current = head;
                while (current->next && current->next->next) {
                    current = current->next;
                }
                delete current->next;
                current->next = nullptr;
            }
            --list_size;
        }
    }

    // Returns a const reference to the value of the head node
    const T& front() const {
        return head->value;
    }

    // Returns the current size of the list
    int size() const {
        return list_size;
    }

    // Removes all nodes from the list
    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        list_size = 0;
    }

private:
    Node* head;
    int list_size;
};