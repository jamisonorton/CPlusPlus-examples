#pragma once

#include <vector>

template<class T>
class VectorSet {
private:
    std::vector<T> elements;

public:
    bool contains(T item) const {
        for (const auto& elem : elements) {
            if (elem == item) {
                return true;
            }
        }
        return false;
    }

    bool insert(T item) {
        if (!contains(item)) {
            elements.push_back(item);
            return true;
        }
        return false;
    }

    bool remove(T item) {
        for (auto it = elements.begin(); it != elements.end(); ++it) {
            if (*it == item) {
                elements.erase(it);
                return true;
            }
        }
        return false;
    }

    int size() const {
        return elements.size();
    }

    bool empty() const {
        return elements.empty();
    }

    void clear() {
        elements.clear();
    }
};
