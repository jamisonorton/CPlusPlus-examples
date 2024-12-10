#pragma once

#include <vector>
#include <algorithm>  // For std::swap

template<class T>
int medianOfThree(std::vector<T>& array, int left, int right) {
    int middle = (left + right) / 2;

    // Sort the three elements at left, middle, and right
    if (array[left] > array[middle]) {
        std::swap(array[left], array[middle]);
    }
    if (array[left] > array[right]) {
        std::swap(array[left], array[right]);
    }
    if (array[middle] > array[right]) {
        std::swap(array[middle], array[right]);
    }

    // Return the index of the median element (which will be the middle after sorting)
    return middle;
}

template<class T>
int partition(std::vector<T>& array, int left, int right) {
    // Choose pivot using median of three
    int middle = medianOfThree(array, left, right);
    T pivot = array[middle];

    // Move the pivot to the leftmost position
    std::swap(array[left], array[middle]);

    int up = left + 1;
    int down = right;

    // Perform partitioning
    while (up <= down) {
        // Increment 'up' while array[up] <= pivot
        while (up <= right && array[up] <= pivot) {
            up++;
        }

        // Decrement 'down' while array[down] > pivot
        while (array[down] > pivot) {
            down--;
        }

        // Swap elements if up is still to the left of down
        if (up < down) {
            std::swap(array[up], array[down]);
        }
    }

    // Place the pivot in its correct position
    std::swap(array[left], array[down]);

    return down;  // Return pivot index
}

template<class T>
void sort_helper(std::vector<T>& array, int left, int right) {
    if (left < right) {
        // Partition the array and get the pivot index
        int pivot_index = partition(array, left, right);

        // Recursively sort the left and right subarrays
        sort_helper(array, left, pivot_index - 1);
        sort_helper(array, pivot_index + 1, right);
    }
}

template<class T>
void sort(std::vector<T>& array) {
    sort_helper(array, 0, array.size() - 1);
}