#include "ProductsInput.h"
#include "IndustrialProduct.h"
#include <iostream>
using namespace std;

string ProductsInput::get_name() {
    cout << "==>> Enter a name of a new product: ";
    string product_name;
    getline(cin, product_name);
    return product_name;
}

Date ProductsInput::get_release_date() {
    string release_date_str;
    while (true){
        cout << "==>> Enter a release date for a new product (dd-mm-yyyy): ";
        getline(cin, release_date_str);
        try{
            return Date(release_date_str);
        }catch (invalid_argument& e){
            cout << "==>> Error: invalid data input. Try again." << endl;
            continue;
        }
    }
}

float ProductsInput::get_price() {
    float price;
    string input;
    cout << "==>> Enter a price for a new product: ";
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

float ProductsInput::get_amount() {
    float price;
    string input;
    cout << "==>> Enter an amount of a new product: ";
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

int ProductsInput::get_storage_term() {
    int price;
    string input;
    cout << "==>> Enter a storage term of a new food product: ";
    do {
        getline(cin, input);
        try {
            price = stoi(input);
        } catch (...) {
            cout << "Error: Incorrect input. Try again." << endl;
            continue;
        }
        break;
    } while (true);
    return price;
}

Date ProductsInput::get_inspection_date() {
    cout << "==>> Enter a date for products inspection: ";
    while(true){
        string input_date;
        getline(cin, input_date);
        try{
            return Date(input_date);
        }catch(invalid_argument& e) {
            cout << "Error: Invalid input date." << endl;
        }
    }
}

string ProductsInput::get_transportation_conditions(){
    string transportation_conditions;
    cout << "==>> Enter transportation conditions: ";
    getline(cin, transportation_conditions);
    return transportation_conditions;
}

IndustrialProduct::StorageLocation ProductsInput::get_storage_location() {
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
