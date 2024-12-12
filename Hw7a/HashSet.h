#pragma once
#include <iostream>
#include <vector>
using std::vector;
#include <list>
using std::list;
#include <functional>
using std::hash;

template<class T>
class HashSet {
private:
    vector<list<T>> table;  // Vector of lists for chaining
    int currentSize;  // Number of elements in the set
    int bucketCount;  // Number of buckets (size of the table)
    float loadFactorThreshold;  // Threshold for load factor to trigger resizing

    // Helper function to calculate the hash index for a given item
    size_t hashFunction(const T& item) const {
        return hash<T>{}(item) % bucketCount;
    }

    // Resize the table when the load factor exceeds the threshold
    void resize() {
        bucketCount *= 2;  // Double the number of buckets
        vector<list<T>> newTable(bucketCount);

        // Rehash all items into the new table
        for (const auto& bucket : table) {
            for (const T& item : bucket) {
                size_t newIndex = hash<T>{}(item) % bucketCount;
                newTable[newIndex].push_back(item);
            }
        }

        table = std::move(newTable);
    }

public:
    HashSet(int initialSize = 8, float loadFactorThreshold = 0.75)
        : currentSize(0), bucketCount(initialSize), loadFactorThreshold(loadFactorThreshold) {
        table.resize(bucketCount);
    }

    ~HashSet() {}

    bool insert(T item) {
        if (contains(item)) {
            return false;  // Item already exists
        }

        if (currentSize + 1 > bucketCount * loadFactorThreshold) {
            resize();  // Resize the table if load factor exceeds threshold
        }

        size_t index = hashFunction(item);
        table[index].push_back(item);
        currentSize++;
        return true;
    }

    bool remove(T item) {
        size_t index = hashFunction(item);
        auto& bucket = table[index];

        // Try to find the item in the bucket
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (*it == item) {
                bucket.erase(it);
                currentSize--;
                return true;
            }
        }
        return false;  // Item not found
    }

    bool contains(T item) const {
        size_t index = hashFunction(item);
        const auto& bucket = table[index];

        // Check if the item exists in the bucket
        for (const auto& elem : bucket) {
            if (elem == item) {
                return true;
            }
        }
        return false;
    }

    void clear() {
        table.clear();
        table.resize(bucketCount);  // Keep the same number of buckets
        currentSize = 0;
    }

    int size() const {
        return currentSize;
    }
};