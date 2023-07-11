#ifndef LAB5_6_COLLECTIONS_OUTPUT_H
#define LAB5_6_COLLECTIONS_OUTPUT_H

#include "Multiset.h"

class Output {
public:
    template<typename T>
    static void PrintMultiset(Multiset<T>& multiset) {
        std::cout << "==>> Multiset contains: ";
        typename Multiset<T>::Iterator iter = multiset.begin();
        while (iter != multiset.end()) {
            std::cout << *iter << " ";
            ++iter;
        }
        std::cout << std::endl;
    }
};

#endif //LAB5_6_COLLECTIONS_OUTPUT_H
