#include "IndustrialProductsCostCalculator.h"
/*
float IndustrialProductsCostCalculator::count_products_cost_by_location(const IndustrialProductsRange& range,
                                                                        const IndustrialProduct::StorageLocation& selected_storage_location) {
    float cost = 0;
    for(int i=0; i < range.get_size(); i++){
        IndustrialProduct* product = range.get_product(i);
        if(product->get_storage_location() == selected_storage_location){
            cost += product->get_price() * product->get_amount();
        }
    }
    return cost;
}
*/