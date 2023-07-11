#ifndef LAB4_5_INHERITANCE_INDUSTRIALPRODUCTSRANGE_H
#define LAB4_5_INHERITANCE_INDUSTRIALPRODUCTSRANGE_H

#include "../IndustrialProduct.h"

class IndustrialProductsRange {
public:
    // A constructor
    IndustrialProductsRange(): range(nullptr), size(0){};
    // A destructor
    ~IndustrialProductsRange();
    void add_product(IndustrialProduct new_product);

    friend ostream& operator << (ostream& out, IndustrialProductsRange& range);

    [[nodiscard]] int get_size() const;
    [[nodiscard]] IndustrialProduct* get_product(const int& num) const;
    float count_products_cost_by_location(const IndustrialProduct::StorageLocation& selected_storage_location) const;
    void fill_industrial_products_range();

private:
    IndustrialProduct** range;
    int size;
};


#endif //LAB4_5_INHERITANCE_INDUSTRIALPRODUCTSRANGE_H