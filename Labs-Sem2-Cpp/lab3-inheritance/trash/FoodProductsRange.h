#ifndef LAB4_5_INHERITANCE_FOODPRODUCTSRANGE_H
#define LAB4_5_INHERITANCE_FOODPRODUCTSRANGE_H


#include "../FoodProduct.h"
using namespace std;

class FoodProductsRange {
public:
    // a constructor
    FoodProductsRange(): range(nullptr), size(0){};
    // a destructor
    ~FoodProductsRange();

    void add_product(FoodProduct new_product) ;
    [[nodiscard]] int get_size() const;
    [[nodiscard]] FoodProduct* get_product(const int& num) const;

    [[nodiscard]] float count_spoiled_products_cost(const Date& inspection_date) const;

    friend ostream& operator << (ostream& out, const FoodProductsRange& range);
    void fill_food_products_range();

private:
    FoodProduct** range;
    int size;
};


#endif //LAB4_5_INHERITANCE_FOODPRODUCTSRANGE_H
