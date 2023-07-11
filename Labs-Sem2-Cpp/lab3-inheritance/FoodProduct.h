#ifndef LAB4_5_INHERITANCE_FOODPRODUCT_H
#define LAB4_5_INHERITANCE_FOODPRODUCT_H

#include "Product.h"
#include "Date.h"
#include "ProductsInput.h"
using namespace std;

class FoodProduct: public Product {
public:
    // a constructor
    FoodProduct(string name, Date release_date, float price, float amount, int storage_term):
            Product(std::move(name), release_date, price, amount), storage_term(storage_term){};

    [[nodiscard]] int get_storage_term() const;
    bool is_spoiled(const Date& inspection_date);

    static FoodProduct create_by_user_input();

    // unused
    [[maybe_unused]] void set_storage_term(const int& new_storage_term);

private:
    int storage_term;
};

#endif //LAB4_5_INHERITANCE_FOODPRODUCT_H