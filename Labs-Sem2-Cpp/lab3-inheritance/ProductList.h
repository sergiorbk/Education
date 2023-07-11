#ifndef LAB4_5_INHERITANCE_PRODUCTLIST_H
#define LAB4_5_INHERITANCE_PRODUCTLIST_H

#include "IndustrialProduct.h"
#include "Date.h"

template<typename T>
class ProductList {
private:
    T** products;
    int size;

public:
    ProductList();
    ~ProductList();

    [[nodiscard]] int get_size() const;
    void add_product(T new_product);
    void fill_list();
    [[nodiscard]] T* get_product(const int& num) const;

    [[nodiscard]] float count_spoiled_products_cost(const Date& inspection_date) const{
        float spoiled_products_cost = 0;
        for(int i=0; i < size; i++){
            T* product = get_product(i);
            if(product->is_spoiled(inspection_date)){
                spoiled_products_cost += product->get_price() * product->get_amount();
            }
        }
        return spoiled_products_cost;
    }

    float count_products_cost_by_location(const IndustrialProduct::StorageLocation &selected_storage_location){
        float cost = 0;
        for(int i=0; i < size; i++){
            IndustrialProduct* product = get_product(i);
            if(product->get_storage_location() == selected_storage_location){
                cost += product->get_price() * product->get_amount();
            }
        }
        return cost;
    }

};

#include "ProductList.tpp"
#endif //LAB4_5_INHERITANCE_PRODUCTLIST_H
