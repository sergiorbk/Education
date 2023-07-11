#ifndef LAB4_5_INHERITANCE_INDUSTRIALPRODUCT_H
#define LAB4_5_INHERITANCE_INDUSTRIALPRODUCT_H

#include "Product.h"
#include <string>
using namespace std;

class IndustrialProduct: public Product{
public:
    enum StorageLocation {WAREHOUSE, SHOWCASE};

    IndustrialProduct(string name, Date release_date, float price, float amount,
       string transportation_conditions, StorageLocation storage_location): Product(std::move(name), release_date, price, amount),
       transportation_conditions(std::move(transportation_conditions)), storage_location(storage_location){}

       [[nodiscard]] string get_transportation_conditions() const;
       [[nodiscard]] StorageLocation get_storage_location() const;
       static string get_storage_location_name(const StorageLocation& storageLocation);
       static IndustrialProduct create_by_user_input();

       // unused
       [[maybe_unused]] void set_transportation_conditions(const string& new_conditions);
       [[maybe_unused]] void set_storage_location(const StorageLocation& new_storage_location);
private:
    string transportation_conditions;
    StorageLocation storage_location;
};

#endif //LAB4_5_INHERITANCE_INDUSTRIALPRODUCT_H