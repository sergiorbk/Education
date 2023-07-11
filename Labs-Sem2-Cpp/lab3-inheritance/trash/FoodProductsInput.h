#ifndef LAB4_5_INHERITANCE_FOODPRODUCTSINPUT_H
#define LAB4_5_INHERITANCE_FOODPRODUCTSINPUT_H

#include "../ProductsInput.h"
#include <iostream>
#include <string>
#include "FoodProductsRange.h"

using namespace std;

class FoodProductsInput: public ProductsInput {
public:
    /*
    void fill_food_products_range(FoodProductsRange* range);
    static Date get_inspection_date();
     */

private:
    /*
    string get_name() override;
    Date get_release_date() override;
    float get_price() override;
    float get_amount() override;
    static int get_storage_term();
     */
};

#endif //LAB4_5_INHERITANCE_FOODPRODUCTSINPUT_H