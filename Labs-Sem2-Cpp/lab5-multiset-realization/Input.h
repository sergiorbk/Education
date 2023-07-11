#ifndef LAB5_6_COLLECTIONS_INPUT_H
#define LAB5_6_COLLECTIONS_INPUT_H


#include <iostream>
#include "Multiset.h"
#include <conio.h>
#include <limits>

using namespace std;

class Input {
public:
    template <typename T>
    static Multiset<T> init_multiset_by_user_input(int len) {
        Multiset<T> multiset;

        std::cout << "==>> Enter values for multiset." << std::endl;

        for (int i=0; i < len; i++) {
            T value = get_valid_input<T>("");
            multiset.insert(value);
        }

        return multiset;
    }

    static int get_multiset_size_from_user(){
        int size = get_valid_input<int>("==>> Enter container's size: ");
        return size;
    }


    template <typename T>
    static T get_valid_input(const std::string& message) {
        while (true) {
            std::cout << message;
            T input;
            std::cin >> input;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please try again." << std::endl;
            } else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return input;
            }
        }
    }
};


#endif //LAB5_6_COLLECTIONS_INPUT_H
