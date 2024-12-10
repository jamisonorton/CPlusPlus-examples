#pragma once

#include <iostream>
#include <stdexcept>

template<class T>
class Vector {
private:
    T* data;           // Pointer to the underlying array
    int current_size;  // Current number of elements in the vector
    int current_capacity; // Current capacity of the vector

    // Helper function to resize the array
    void grow() {
        current_capacity *= 2;
        T* new_data = new T[current_capacity];

        // Copy existing elements to new array
        for (int i = 0; i < current_size; ++i) {
            new_data[i] = data[i];
        }

        // Delete old array and point to new one
        delete[] data;
        data = new_data;
    }

public:
    // Constructor
    Vector() : data(new T[1]), current_size(0), current_capacity(1) {}

    // Destructor
    ~Vector() {
        delete[] data;
    }

    // Append an item to the end of the vector
    void push_back(T item) {
        // If the array is full, resize it
        if (current_size == current_capacity) {
            grow();
        }

        data[current_size] = item;
        ++current_size;
    }

    // Insert an item at a specific position
    void insert(T item, int position) {
        if (position < 0 || position > current_size) {
            throw std::out_of_range("Index out of range");
        }

        // If the array is full, resize it
        if (current_size == current_capacity) {
            grow();
        }

        // Shift elements to the right to make room for the new element
        for (int i = current_size; i > position; --i) {
            data[i] = data[i - 1];
        }

        // Insert the new element
        data[position] = item;
        ++current_size;
    }

    // Remove the element at a specific position
    void remove(int position) {
        if (position < 0 || position >= current_size) {
            throw std::out_of_range("Index out of range");
        }

        // Overwrite the element at the specified position
        for (int i = position; i < current_size - 1; ++i) {
            data[i] = data[i + 1];
        }

        --current_size;
    }

    // Access the item at a given index
    T& operator[](int index) {
        if (index < 0 || index >= current_size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Return the number of elements in the vector
    int size() const {
        return current_size;
    }

    // Clear the vector, making it empty
    void clear() {
        current_size = 0;
    }
};