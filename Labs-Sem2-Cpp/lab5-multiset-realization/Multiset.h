#ifndef MULTISET_H
#define MULTISET_H

#include <iostream>

template <typename T>
class Multiset {
private:
    class Node {
    public:
        T value;
        Node* next;
        explicit Node(const T& val) : value(val), next(nullptr) {}
    };

    Node* head;

public:
    Multiset();
    ~Multiset();
    Multiset<T>& operator=(const Multiset<T>& other);
    void insert(const T& value);
    void erase(const T& value);
    [[nodiscard]] int get_size() const;
    void clear();
    //void print() const;
    [[nodiscard]] bool is_empty() const;
    bool contains(const T& value) const;
    Multiset<T> intersection(const Multiset<T>& other) const;

    class Iterator {
    private:
        Node* current;
        const Multiset<T>* multiset;

    public:
        Iterator(Node* node, const Multiset<T>* set);
        void set_to_begin();
        [[nodiscard]] bool is_end() const;
        T get_value() const;
        void next();
        bool operator!=(const Iterator& other) const;
        void operator++();
        void operator--();
        T& operator*() const;
    };

    Iterator begin();
    Iterator end();
};

#include "Multiset.tpp"

#endif // MULTISET_H