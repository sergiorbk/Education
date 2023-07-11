#include "IndustrialProductsInput.h"
#include <conio.h>
#include <iostream>
using namespace std;
/*
string IndustrialProductsInput::get_transportation_conditions(){
    string transportation_conditions;
    cout << "==>> Enter transportation conditions: ";
    getline(cin, transportation_conditions);
    return transportation_conditions;
}

IndustrialProduct::StorageLocation IndustrialProductsInput::get_storage_location() {
    int storage_location_id;
    cout << "==>> Enter a storage location of industrial product: " << endl;
    cout << "==>> [1] - Warehouse [2] - Showcase" << endl;
    do{
        string storage_location_id_str;
        getline(cin, storage_location_id_str);
        try{
            storage_location_id = stoi(storage_location_id_str);
        }catch (...){
            cout << "==>> Error: invalid data input. Try again." << endl;
            continue;
        }
    }while(storage_location_id <= 0 || storage_location_id >= 3);

    if(storage_location_id == 1){
        return IndustrialProduct::WAREHOUSE;
    }else{
        return IndustrialProduct::SHOWCASE;
    }
}

string IndustrialProductsInput::get_name() {
    cout << "==>> Enter a name of a new industrial product: ";
    string product_name;
    getline(cin, product_name);
    return product_name;
}

Date IndustrialProductsInput::get_release_date() {
    string release_date_str;
    while (true){
        cout << "==>> Enter a release date for a new industrial product (dd-mm-yyyy): ";
        getline(cin, release_date_str);
        try{
            return Date(release_date_str);
        }catch (invalid_argument& e){
            cout << "==>> Error: invalid data input. Try again." << endl;
            continue;
        }
    }
}

float IndustrialProductsInput::get_price() {
    float price;
    string input;
    cout << "==>> Enter a price for a new industrial product: ";
    do {
        getline(cin, input);
        try {
            price = stof(input);
        } catch (...) {
            cout << "Error: Incorrect input. Try again." << endl;
            continue;
        }
        break;
    } while (true);
    return price;
}

float IndustrialProductsInput::get_amount() {
    float price;
    string input;
    cout << "==>> Enter an amount of a new industrial product: ";
    do {
        getline(cin, input);
        try {
            price = stof(input);
        } catch (...) {
            cout << "Error: Incorrect input. Try again." << endl;
            continue;
        }
        break;
    } while (true);
    return price;
}

void IndustrialProductsInput::fill_industrial_products_range(IndustrialProductsRange* range) {
    cout << "==================== Filling an Industrial Products' range ====================" << endl;
    while (true) {
        cout << ">>>================= Adding a new Industrial Product ====================" << endl;
        string input_name = get_name();
        Date input_date = get_release_date();
        float input_price = get_price();
        float input_amount = get_amount();
        string input_transportation_conditions = get_transportation_conditions();
        IndustrialProduct::StorageLocation storageLocation = get_storage_location();

        range->add_product(IndustrialProduct(input_name, input_date, input_price,
        input_amount,input_transportation_conditions, storageLocation));

        cout << "\n==>> Would you like to add another Industrial Product?" << endl;
        cout << "==>> Enter '1' to add or any key to exit..." << endl;

        if (getch() == '1') {
            draw_line();
        } else {
            break;
        }
    }
}
 */