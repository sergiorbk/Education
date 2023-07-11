#include "FoodProductsInput.h"
#include <conio.h>
#include <iostream>

using namespace std;
/*
string FoodProductsInput::get_name() {
    cout << "==>> Enter a name of a new food product: ";
    string product_name;
    getline(cin, product_name);
    return product_name;
}

Date FoodProductsInput::get_release_date() {
    string release_date_str;
    while (true){
        cout << "==>> Enter a release date for a new food product (dd-mm-yyyy): ";
        getline(cin, release_date_str);
        try{
            return Date(release_date_str);
        }catch (invalid_argument& e){
            cout << "==>> Error: invalid data input. Try again." << endl;
            continue;
        }
    }
}

float FoodProductsInput::get_price() {
    float price;
    string input;
    cout << "==>> Enter a price for a new food product: ";
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

float FoodProductsInput::get_amount() {
    float price;
    string input;
    cout << "==>> Enter an amount of a new food product: ";
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

int FoodProductsInput::get_storage_term() {
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



void FoodProductsInput::fill_food_products_range(FoodProductsRange* range) {
    cout << "==================== Filling a products' range ====================" << endl;
    while (true) {
        cout << ">>>================= Adding a new Food Product ====================" << endl;
        string input_name = get_name();
        Date input_date = get_release_date();
        float input_price = get_price();
        float input_amount = get_amount();
        int input_storage_term = get_storage_term();

        range->add_product(FoodProduct(input_name, input_date, input_price, input_amount, input_storage_term));
        cout << "\n==>> Would you like to add another Food Product?" << endl;
        cout << "==>> Enter '1' to add or any key to exit..." << endl;

        if (getch() == '1') {
            draw_line();
        } else {
            break;
        }
    }
}
 */