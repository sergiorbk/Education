#ifndef LAB4_5_INHERITANCE_PRODUCTSINPUT_H
#define LAB4_5_INHERITANCE_PRODUCTSINPUT_H

#include <string>
#include <iostream>
#include "Date.h"
#include "IndustrialProduct.h"
#include <conio.h>
using namespace std;

class ProductsInput {
public:
    static bool is_exit(){
        cout << "\n==>> Press '1' to exit or ANY KEY to continue..." << endl;
        if(getch() == '1'){
            return true;
        }else{
            return false;
        }
    }

    static void draw_line(){
        cout << "\n\n============================================================\n\n";
    }

    string get_name();
    Date get_release_date();
    float get_price();
    float get_amount();

    Date get_inspection_date();
    int get_storage_term();

    string get_transportation_conditions();

    IndustrialProduct::StorageLocation get_storage_location();
};

#endif //LAB4_5_INHERITANCE_PRODUCTSINPUT_H