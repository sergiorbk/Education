#include "IndustrialProductsOutput.h"
#include "../IndustrialProduct.h"
#include "IndustrialProductsRange.h"
#include <string>
#include <iostream>
using namespace std;
//overengeniring
//class Output {
//    static void PrintProducts(const Product *p) {
//        cout << *(p) << endl;
//    }
//};
// <<
// >>
/*
void IndustrialProductsOutput::print_products_range(const IndustrialProductsRange& range){
    draw_line();
    cout << "============================== Industrial Products Range ========================================" << endl;
    draw_line();
    cout << "Name\t\tRelease Date\t\tPrice\t\tAmount\t\tStorage location\tTrans.conditions\t\t"<< endl;

    for(int i=0; i < range.get_size(); i++){
        IndustrialProduct* product = range.get_product(i);
        cout << product->get_name() << "\t\t";
        cout << product->get_release_date().to_string() << "\t\t";
        cout << product->get_price() << "\t\t";
        cout << product->get_amount() << "\t\t";
        cout << IndustrialProduct::get_storage_location_name(product->get_storage_location()) << "\t\t";
        cout << product->get_transportation_conditions() << "\t\t";
        cout << endl;

    }
    draw_line();
    cout << endl;
}
 */
/*
void IndustrialProductsOutput::draw_line() {
    cout << "=====================================================================================================\n";
}

void IndustrialProductsOutput::print_products_cost_by_storage(const float &total_cost,
                                                              IndustrialProduct::StorageLocation storageLocation) {
    cout << "==>> Total Industrial products' cost that located at "
         << IndustrialProduct::get_storage_location_name(storageLocation) << " is " << total_cost << endl;
}
*/