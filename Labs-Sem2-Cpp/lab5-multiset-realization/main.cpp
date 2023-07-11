#include <iostream>
#include "Multiset.h"
#include "Menu.h"
#include "Input.h"
#include "Output.h"
using namespace std;

int main() {
    Menu menu = Menu();

    while (true) {
        int mainMenuChoice = menu.show_main_menu();

        if (mainMenuChoice == 1) {
            cout << "\n========== CREATING A NEW MULTISET ==========" << endl;
            int size = Input::get_multiset_size_from_user();

            int multisetType = menu.show_multiset_type_selection();
            switch (multisetType) {
                case 1: {
                    Multiset<int> multiset = Input::init_multiset_by_user_input<int>(size);
                    Output::PrintMultiset(multiset);
                    cout << endl;
                    menu.show_multiset_menu(multiset);
                    break;
                }

                case 2: {
                    Multiset<float> multiset = Input::init_multiset_by_user_input<float>(size);
                    Output::PrintMultiset(multiset);
                    cout << endl;
                    menu.show_multiset_menu(multiset);
                    break;
                }

                case 3: {
                    Multiset<double> multiset = Input::init_multiset_by_user_input<double>(size);
                    Output::PrintMultiset(multiset);
                    cout << endl;
                    menu.show_multiset_menu(multiset);
                    break;
                }

                case 4: {
                    Multiset<char> multiset = Input::init_multiset_by_user_input<char>(size);
                    Output::PrintMultiset(multiset);
                    cout << endl;
                    menu.show_multiset_menu(multiset);
                    break;
                }

                case 5: {
                    Multiset<string> multiset = Input::init_multiset_by_user_input<string>(size);
                    Output::PrintMultiset(multiset);
                    menu.show_multiset_menu(multiset);
                    break;
                }

                default:
                    break;
            }

        } else {
            break;
        }
    }

    return 0;
}