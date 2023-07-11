#include "ProductsOutput.h"

void ProductsOutput::print_food_products_list(const ProductList<FoodProduct> &products_to_print) {
    cout << "=====================================================================================================\n";
    cout << "====================================== Food Products Range ======================================"<< std::endl;
    cout << "=====================================================================================================\n";
    cout << "Name\t\tRelease Date\t\tPrice\t\tAmount\t\tStorage Term\t\t" << std::endl;

    for (int i = 0; i < products_to_print.get_size(); i++) {
        FoodProduct* product = products_to_print.get_product(i);
        cout << product->get_name() << "\t\t";
        cout << product->get_release_date().to_string() << "\t\t";
        cout << product->get_price() << "\t\t";
        cout << product->get_amount() << "\t\t";
        cout << product->get_storage_term() << "\t\t" << std::endl;
    }
    cout << "=====================================================================================================\n";
    cout << std::endl;
}

void ProductsOutput::print_industrial_products_list(const ProductList<IndustrialProduct> &products_to_print) {
    cout << "=====================================================================================================\n";
    cout << "============================== Industrial Products Range ========================================" << std::endl;
    cout << "=====================================================================================================\n";
    cout << "Name\t\tRelease Date\t\tPrice\t\tAmount\t\tStorage location\tTrans.conditions\t\t"<< std::endl;

    for(int i=0; i < products_to_print.get_size(); i++){
        IndustrialProduct* product = products_to_print.get_product(i);
        cout << product->get_name() << "\t\t";
        cout << product->get_release_date().to_string() << "\t\t";
        cout << product->get_price() << "\t\t";
        cout << product->get_amount() << "\t\t";
        cout << IndustrialProduct::get_storage_location_name(product->get_storage_location()) << "\t\t";
        cout << product->get_transportation_conditions() << "\t\t";
        cout << std::endl;
    }
    cout << "=====================================================================================================\n";
    std::cout << std::endl;
}


