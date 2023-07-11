#include "IndustrialProductsRange.h"

#include "../ProductsInput.h"
#include "../IndustrialProduct.h"
#include "iostream"

void IndustrialProductsRange::add_product(IndustrialProduct new_product) {
    auto** buffer_range = new IndustrialProduct*[size+1]; // type: IndustrialProduct**
    for(int i=0; i < size; i++){
        buffer_range[i] = range[i];
    }
    buffer_range[size] = new IndustrialProduct(std::move(new_product));
    delete[] range;
    range = buffer_range;
    size++;
}

IndustrialProductsRange::~IndustrialProductsRange() {
    size = 0;
    delete[] range;
}

int IndustrialProductsRange::get_size() const{
    return size;
}

IndustrialProduct* IndustrialProductsRange::get_product(const int& num) const{
    if(num > size-1 && num < 0){
        throw (out_of_range("Invalid index for product."));
    }else{
        return range[num];
    }
}

std::ostream& operator<<(std::ostream& out, IndustrialProductsRange& range_to_print) {
    out << "=====================================================================================================\n";
    out << "============================== Industrial Products Range ========================================" << std::endl;
    out << "=====================================================================================================\n";
    out << "Name\t\tRelease Date\t\tPrice\t\tAmount\t\tStorage location\tTrans.conditions\t\t"<< std::endl;

    for(int i=0; i < range_to_print.size; i++){
        IndustrialProduct* product = range_to_print.get_product(i);
        out << product->get_name() << "\t\t";
        out << product->get_release_date().to_string() << "\t\t";
        out << product->get_price() << "\t\t";
        out << product->get_amount() << "\t\t";
        out << IndustrialProduct::get_storage_location_name(product->get_storage_location()) << "\t\t";
        out << product->get_transportation_conditions() << "\t\t";
        out << std::endl;
    }
    out << "=====================================================================================================\n";
    std::cout << std::endl;
    return out;
}

float IndustrialProductsRange::count_products_cost_by_location(const IndustrialProduct::StorageLocation& selected_storage_location) const {
    float cost = 0;
    for(int i=0; i < size; i++){
        IndustrialProduct* product = get_product(i);
        if(product->get_storage_location() == selected_storage_location){
            cost += product->get_price() * product->get_amount();
        }
    }
    return cost;
}

void IndustrialProductsRange::fill_industrial_products_range() {
    cout << "==================== Filling an Industrial Products' range ====================" << endl;
    while (true) {
        cout << ">>>================= Adding a new Industrial Product ====================" << endl;

        add_product(IndustrialProduct::create_by_user_input());

        cout << "\n==>> Would you like to add another Industrial Product?" << endl;
        cout << "==>> Enter '1' to add or any key to exit..." << endl;

        if (getch() == '1') {
            ProductsInput::draw_line();
        } else {
            break;
        }
    }
}

