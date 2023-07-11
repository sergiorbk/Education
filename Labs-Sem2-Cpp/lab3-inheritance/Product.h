#ifndef LAB4_5_INHERITANCE_PRODUCT_H
#define LAB4_5_INHERITANCE_PRODUCT_H

#include <string>
#include "Date.h"
using namespace std;

class Product {
public:
    [[nodiscard]] string get_name() const;
    [[nodiscard]] Date get_release_date() const;
    [[nodiscard]] float get_price() const;
    [[nodiscard]] float get_amount() const;
    //count_spoiled_products_cost

    // unused
    [[maybe_unused]] void set_name(const string& new_name);
    [[maybe_unused]] void set_release_date(const Date& new_release_date);
    [[maybe_unused]] void set_price(const float& new_price);
    [[maybe_unused]] void set_amount(const float& new_amount);

protected:
    string name;
    Date release_date;
    float price;
    float amount;

    Product(string name, Date release_date, float price, float amount): name(std::move(name)),
    release_date(release_date), price(price), amount(amount){};
};

#endif //LAB4_5_INHERITANCE_PRODUCT_H