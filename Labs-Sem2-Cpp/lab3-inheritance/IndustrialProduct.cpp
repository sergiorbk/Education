#include "IndustrialProduct.h"
#include "ProductsInput.h"
#include <string>

using namespace std;

string IndustrialProduct::get_transportation_conditions() const {
    return transportation_conditions;
}

[[maybe_unused]] void IndustrialProduct::set_transportation_conditions(const string &new_conditions) {
    transportation_conditions = new_conditions;
}

[[maybe_unused]] void IndustrialProduct::set_storage_location(const IndustrialProduct::StorageLocation &new_storage_location) {
    storage_location = new_storage_location;
}

IndustrialProduct::StorageLocation IndustrialProduct::get_storage_location() const {
    return storage_location;
}

string IndustrialProduct::get_storage_location_name(const IndustrialProduct::StorageLocation &storageLocation) {
    switch (storageLocation) {
        case WAREHOUSE:
            return "Warehouse";
        case SHOWCASE:
            return "Showcase";
    }
}

IndustrialProduct IndustrialProduct::create_by_user_input() {
    ProductsInput input;
    string input_name = input.get_name();
    Date input_date = input.get_release_date();
    float input_price = input.get_price();
    float input_amount = input.get_amount();
    string input_transportation_conditions = input.get_transportation_conditions();
    IndustrialProduct::StorageLocation storageLocation = input.get_storage_location();

    return {input_name, input_date, input_price, input_amount, input_transportation_conditions, storageLocation};
}
