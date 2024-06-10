#ifndef LIST_H
#define LIST_H

#include <vector>
#include <iostream>

template<typename T>
class List {
protected:
    std::vector<T> items;

public:
    void operator+(const T &item) {
        items.push_back(item);
    }

    friend std::istream &operator>>(std::istream &is, List<T> &list) {
        T item;
        while (is >> item) {
            list + item;
        }
        return is;
    }

    void display() const {
        for (const auto &item: items) {
            std::cout << item << std::endl;
        }
    }

    size_t size() const {
        return items.size();
    }

    void clear() {
        items.clear();
    }

    typename std::vector<T>::iterator begin() {
        return items.begin();
    }

    typename std::vector<T>::iterator end() {
        return items.end();
    }
};

#endif
