#include "Product.h"
#include <string>
#include "Date.h"
using namespace std;

string Product::get_name() const{
    return name;
}

Date Product::get_release_date() const{
    return release_date;
}

float Product::get_price() const{
    return price;
}

float Product::get_amount() const{
    return amount;
}

// unused
[[maybe_unused]] void Product::set_name(const string& new_name){
    name = new_name;
}

[[maybe_unused]] void Product::set_release_date(const Date& new_release_date){
    release_date = new_release_date;
}

[[maybe_unused]] void Product::set_price(const float& new_price){
    price = new_price;
}

[[maybe_unused]] void Product::set_amount(const float& new_amount){
    amount = new_amount;
}