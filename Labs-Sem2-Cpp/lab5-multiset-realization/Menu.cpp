#include "Menu.h"
int Menu::show_multiset_type_selection(){
    cout << "========== SELECT A DATA TYPE FOR MULTISET ==========" << endl;
    cout << "==>> [1] Integer" << endl;
    cout << "==>> [2] Float" << endl;
    cout << "==>> [3] Double" << endl;
    cout << "==>> [4] Char" << endl;
    cout << "==>> [5] String" << endl;
    cout << "=====================================================" << endl;
    while (true){
        switch(getch()){
            case '1': return 1;
            case '2': return 2;
            case '3': return 3;
            case '4': return 4;
            case '5': return 5;
        }
    }
}

int Menu::show_main_menu(){
    cout << "========== MAIN MENU ==========" << endl;
    cout << "==>> [1] Create a new Multiset." << endl;
    cout << "==>> [2] Exit application." << endl;
    cout << "===============================" << endl;
    while (true){
        switch(getch()){
            case '1':
                return 1;

            case '2':
                return 2;
        }
    }
}