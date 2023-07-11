#ifndef LAB4_5_INHERITANCE_PRODUCTSOUTPUT_H
#define LAB4_5_INHERITANCE_PRODUCTSOUTPUT_H

#include "iostream"
#include "ProductList.h"
#include "FoodProduct.h"
using namespace std;

class ProductsOutput {
public:
    static void print_food_products_list(const ProductList<FoodProduct>& products_to_print) ;
    static void print_industrial_products_list(const ProductList<IndustrialProduct>& products_to_print) ;
};

#endif //LAB4_5_INHERITANCE_PRODUCTSOUTPUT_H
