#ifndef MULTISET_TPP
#define MULTISET_TPP

#include "Multiset.h"

template <typename T>
Multiset<T>::Multiset() : head(nullptr) {}

template <typename T>
Multiset<T>::~Multiset() {
    clear();
}

template <typename T>
Multiset<T>& Multiset<T>::operator=(const Multiset<T>& other) {
    if (this == &other) {
        return *this;
    }
    clear();
    Node* current = other.head;
    while (current != nullptr) {
        insert(current->value);
        current = current->next;
    }
    return *this;
}

template <typename T>
void Multiset<T>::insert(const T& value) {
    Node* newNode = new Node(value);
    if (head == nullptr || value < head->value) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr && value >= current->next->value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

template <typename T>
void Multiset<T>::erase(const T& value) {
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->value == value) {
            if (prev == nullptr) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}

template <typename T>
int Multiset<T>::get_size() const {
    int size = 0;
    Node* current = head;
    while (current != nullptr) {
        size++;
        current = current->next;
    }
    return size;
}

template <typename T>
void Multiset<T>::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

//template <typename T>
//void Multiset<T>::print() const {
//    std::cout << "==>> Multiset contains: ";
//    Node* current = head;
//    while (current != nullptr) {
//        std::cout << current->value << " ";
//        current = current->next;
//    }
//    std::cout << std::endl;
//}

template <typename T>
bool Multiset<T>::is_empty() const {
    return head == nullptr;
}

template <typename T>
bool Multiset<T>::contains(const T& value) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->value == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template <typename T>
Multiset<T> Multiset<T>::intersection(const Multiset<T>& other) const {
    Multiset<T> result;
    Node* current = head;
    while (current != nullptr) {
        if (other.contains(current->value)) {
            result.insert(current->value);
        }
        current = current->next;
    }
    return result;
}

template <typename T>
Multiset<T>::Iterator::Iterator(Node* node, const Multiset<T>* set) : current(node), multiset(set) {}

template <typename T>
void Multiset<T>::Iterator::set_to_begin() {
    current = multiset->head;
}

template <typename T>
bool Multiset<T>::Iterator::is_end() const {
    return current == nullptr;
}

template <typename T>
T Multiset<T>::Iterator::get_value() const {
    if (current == nullptr) {
        throw std::runtime_error("Iterator is at the end");
    }
    return current->value;
}

template <typename T>
void Multiset<T>::Iterator::next() {
    if (current == nullptr) {
        throw std::runtime_error("Iterator is at the end");
    }
    current = current->next;
}

template <typename T>
bool Multiset<T>::Iterator::operator!=(const Iterator& other) const {
    return current != other.current;
}

template <typename T>
void Multiset<T>::Iterator::operator++() {
    if (current == nullptr) {
        throw std::runtime_error("Iterator is at the end");
    }
    current = current->next;
}

template <typename T>
void Multiset<T>::Iterator::operator--() {
    if (current == nullptr) {
        throw std::runtime_error("Iterator is already at the beginning");
    }
    current = current->prev;
}


template <typename T>
T& Multiset<T>::Iterator::operator*() const {
    if (current == nullptr) {
        throw std::runtime_error("Iterator is at the end");
    }
    return current->value;
}

template <typename T>
typename Multiset<T>::Iterator Multiset<T>::begin() {
    return Iterator(head, this);
}

template <typename T>
typename Multiset<T>::Iterator Multiset<T>::end() {
    return Iterator(nullptr, this);
}

#endif // MULTISET_TPP
