#include "FoodProductsRange.h"
#include "../ProductsInput.h"
#include "iostream"
using namespace std;

FoodProductsRange::~FoodProductsRange() {
    size = 0;
    delete[] range;
}

void FoodProductsRange::add_product(FoodProduct new_product) {
    auto** buffer_range = new FoodProduct *[size + 1]; // type: FoodProduct**
    for(int i=0; i < size; i++){
        buffer_range[i] = range[i];
    }
    buffer_range[size] = new FoodProduct(std::move(new_product));
    delete[] range;
    range = buffer_range;
    size++;
}

int FoodProductsRange::get_size() const{
    return size;
}

FoodProduct* FoodProductsRange::get_product(const int& num) const{
    if(num > size-1 && num < 0){
        throw (out_of_range("Invalid index for product."));
    }else{
        return range[num];
    }
}

float FoodProductsRange::count_spoiled_products_cost(const Date& inspection_date) const {
    float spoiled_products_cost = 0;
    for(int i=0; i < size; i++){
        FoodProduct* product = get_product(i);
        if(product->is_spoiled(inspection_date)){
            spoiled_products_cost += product->get_price() * product->get_amount();
        }
    }
    return spoiled_products_cost;
}

std::ostream& operator<<(std::ostream& out, const FoodProductsRange& range) {
    out << "=====================================================================================================\n";
    out << "====================================== Food Products Range ======================================" << std::endl;
    out << "=====================================================================================================\n";
    out << "Name\t\tRelease Date\t\tPrice\t\tAmount\t\tStorage Term\t\t" << std::endl;

    for(int i=0; i < range.get_size(); i++){
        FoodProduct* product = range.get_product(i);
        out << product->get_name() << "\t\t";
        out << product->get_release_date().to_string() << "\t\t";
        out << product->get_price() << "\t\t";
        out << product->get_amount() << "\t\t";
        out << product->get_storage_term() << "\t\t" << std::endl;
    }
    out << "=====================================================================================================\n";
    out << std::endl;
    return out;
}

void FoodProductsRange::fill_food_products_range() {
    cout << "==================== Filling a products' range ====================" << endl;
    while (true) {
        cout << ">>>================= Adding a new Food Product ====================" << endl;

        add_product(FoodProduct::create_by_user_input());

        cout << "\n==>> Would you like to add another Food Product?" << endl;
        cout << "==>> Enter '1' to add or any key to exit..." << endl;

        if (getch() == '1') {
            ProductsInput::draw_line();
        } else {
            break;
        }
    }
}


