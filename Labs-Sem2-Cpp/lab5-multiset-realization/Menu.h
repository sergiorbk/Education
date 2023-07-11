#ifndef LAB5_6_COLLECTIONS_MENU_H
#define LAB5_6_COLLECTIONS_MENU_H

#include "string"
#include "iostream"
#include "conio.h"
#include "Multiset.h"
#include "Input.h"
#include "Output.h"
using namespace std;

class Menu {

public:
    template <typename T>
    void show_multiset_menu(Multiset<T> multiset) {
        while (true) {
            cout << "========== MULTISET MENU ==========" << endl;
            cout << "==>> [1] Check if multiset is empty." << endl;
            cout << "==>> [2] Check if element belongs to multiset." << endl;
            cout << "==>> [3] Delete element from multiset." << endl;
            cout << "==>> [4] Compare multiset." << endl;
            cout << "==>> [5] Work with iterator." << endl;
            cout << "==>> [6] Insert into multiset." << endl;
            cout << "==>> [0] Back to main menu." << endl;
            cout << "=====================================================" << endl;

            // for case 2
            T input_element;
            // for case 3
            T element_to_delete;
            // for case 4
            Multiset<T> multiset_to_compare = Multiset<T>();
            Multiset<T> intersecion_multiset = Multiset<T>();
            // for case 6
            T value_to_insert;
            char decision = getch();
            switch (decision) {
                case '1':
                    if(multiset.is_empty()){
                        cout << "==>> Multiset is empty." << endl;
                    }else{
                        cout << "==>> Multiset is not empty." << endl;
                    }
                    break;

                case '2':
                    input_element = Input::get_valid_input<T>(
                            "==>> Enter element to check does it belong to multiset: ");

                    if(multiset.contains(input_element)){
                        cout << "Element " << input_element << " belongs to multiset." << endl;
                    }else{
                        cout << "Element " << input_element << " does not belong to multiset." << endl;
                    }
                    break;

                case '3':
                    element_to_delete = Input::get_valid_input<T>("Enter element to delete from multiset: ");
                    multiset.erase(element_to_delete);
                    cout << "========== Multiset after deleting ==========" << endl;
                    Output::PrintMultiset(multiset);
                    cout << endl;
                    break;

                case '4':
                    cout << "========== COMPARING MULTISET S ==========" << endl;
                    cout << "==>> Creating another multiset..." << endl;
                    multiset_to_compare = Input::init_multiset_by_user_input<T>(multiset.get_size());
                    cout << "==>> A multiset for intersection: ";
                    Output::PrintMultiset(multiset_to_compare);
                    cout << endl;

                    intersecion_multiset = multiset.intersection(multiset_to_compare);
                    cout << "==>> The intersection multiset of multiset 1: ";
                    Output::PrintMultiset(multiset);
                    cout << " and multiset 2: ";
                    Output::PrintMultiset(multiset_to_compare);
                    cout << "\n==>> is: ";
                    Output::PrintMultiset(intersecion_multiset);
                    break;


                case '5':
                    show_iterator_menu(multiset);
                    break;

                case '6':
                    cout << "==>> Multiset before inserting: ";
                    Output::PrintMultiset(multiset);
                    cout << endl;
                    value_to_insert = Input::get_valid_input<T>("==>> Enter a value to insert: ");
                    multiset.insert(value_to_insert);
                    cout << "==>> Multiset after inserting: ";
                    Output::PrintMultiset(multiset);
                    cout << endl;
                    break;

                case '0':
                    return;
            }

            cout << "\n==>> Press any key to continue." << endl;
            getch();
        }

    }

    template<typename T>
    void show_iterator_menu(Multiset<T> multiset) {

        typename Multiset<T>::Iterator iterator = multiset.begin();

        while (true) {
            cout << "========== ITERATOR SUBMENU ==========" << endl;
            cout << "==>> [1] Set iterator to the beginning." << endl;
            cout << "==>> [2] Check if the iterator is at the end." << endl;
            cout << "==>> [3] Access the value of the current element." << endl;
            cout << "==>> [4] Move to the next element." << endl;
            cout << "==>> [0] Exit." << endl;
            cout << "===========================" << endl;

            switch (getch()) {
                case '1':
                    iterator = multiset.begin();
                    cout << "==>> Iterator set to the beginning." << endl;
                    if (iterator != multiset.end()) {
                        cout << "==>> Initial element value: " << *iterator << endl;
                    } else {
                        cout << "==>> The multiset is empty." << endl;
                    }
                    break;

                case '2':
                    if (iterator != multiset.end()) {
                        cout << "==>> The iterator is not at the end." << endl;
                    } else {
                        cout << "==>> The iterator is at the end." << endl;
                    }
                    break;

                case '3':
                    if (iterator != multiset.end()) {
                        cout << "==>> Current element value: " << *iterator << endl;
                        typename Multiset<T>::Iterator next = iterator;
                        ++next;
                        if (next != multiset.end()) {
                            cout << "==>> Next element value: " << *next << endl;
                        }
                    } else {
                        cout << "==>> The iterator is at the end." << endl;
                    }
                    break;

                case '4':
                    if (iterator != multiset.end()) {
                        cout << "==>> Current element value: " << *iterator << endl;
                        ++iterator;
                        if (iterator != multiset.end()) {
                            cout << "==>> Moved to the next element." << endl;
                            cout << "==>> Next element value: " << *iterator << endl;
                        } else {
                            cout << "==>> Moved to the end of the multiset." << endl;
                        }
                    } else {
                        cout << "==>> The iterator is at the end." << endl;
                    }
                    break;


                case '0':
                    return;
            }

            cout << "\n==>> Press any key to continue." << endl;
            getch();
        }
    }


int show_multiset_type_selection();
int show_main_menu();

};


#endif //LAB5_6_COLLECTIONS_MENU_H