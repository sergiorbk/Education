#include "FoodProduct.h"
#include "Date.h"
using namespace std;

bool FoodProduct::is_spoiled(const Date& inspection_date) {
    if(inspection_date > release_date + storage_term){
        return true;
    }else{
        return false;
    }
}

int FoodProduct::get_storage_term() const{
    return storage_term;
}

// unused
[[maybe_unused]] void FoodProduct::set_storage_term(const int &new_storage_term) {
    storage_term = new_storage_term;
}

FoodProduct FoodProduct::create_by_user_input(){
    ProductsInput input;
    string input_name = input.get_name();
    Date input_date = input.get_release_date();
    float input_price = input.get_price();
    float input_amount = input.get_amount();
    int input_storage_term = input.get_storage_term();
    return {input_name, input_date, input_price, input_amount, input_storage_term};
}