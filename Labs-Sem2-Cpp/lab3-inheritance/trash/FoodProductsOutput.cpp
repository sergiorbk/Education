#include "FoodProductsOutput.h"
#include "FoodProductsRange.h"
#include <string>
#include <iostream>
using namespace std;
/*
void FoodProductsOutput::print_products_range(const FoodProductsRange& range){
    draw_line();
    cout << "====================================== Food Products Range ======================================" << endl;
    draw_line();
    cout << "Name\t\tRelease Date\t\tPrice\t\tAmount\t\tStorage Term\t\t" << endl;

    for(int i=0; i < range.get_size(); i++){
        FoodProduct* product = range.get_product(i);
        cout << product->get_name() << "\t\t";
        cout << product->get_release_date().to_string() << "\t\t";
        cout << product->get_price() << "\t\t";
        cout << product->get_amount() << "\t\t";
        cout << product->get_storage_term() << "\t\t" << endl;
    }
    draw_line();
    cout << endl;
}

void FoodProductsOutput::draw_line(){
    cout << "=======================================================================================================\n";
}

void FoodProductsOutput::print_spoiled_products_cost(const float &cost) {
    cout << "==>> Total spoiled products' cost is " << cost << endl;
}
*/