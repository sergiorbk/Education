#include "ProductList.h"
#include "ProductsInput.h"
#include "iostream"
#include "FoodProduct.h"

using namespace std;

template<typename T>
ProductList<T>::ProductList():products(nullptr), size(0){}

template<typename T>
ProductList<T>::~ProductList() {
    size = 0;
    delete[] products;
}

template<typename T>
void ProductList<T>::add_product(T new_product) {
    T** buffer_range = new T *[size];
    for(int i=0; i < size; i++){
        buffer_range[i] = products[i];
    }
    buffer_range[size] = new T(std::move(new_product));
    delete[] products;
    products = buffer_range;
    size++;
}

template<typename T>
int ProductList<T>::get_size() const{
    return size;
}

template<typename T>
T* ProductList<T>::get_product(const int& num) const{
    if(num > size-1 && num < 0){
        throw (out_of_range("Invalid index for product."));
    }else{
        return products[num];
    }
}

template<typename T>
void ProductList<T>::fill_list() {
    if (is_same<T, FoodProduct>::value) {
        cout << "==================== Filling a Food products' range ====================" << endl;
        while (true) {
            cout << ">>>================= Adding a new Food Product ====================" << endl;
            add_product(T::create_by_user_input());

            cout << "\n==>> Would you like to add another product?" << endl;
            cout << "==>> Enter '1' to add or any key to exit..." << endl;

            if (getch() == '1') {
                ProductsInput::draw_line();
            } else {
                break;
            }
        }
    } else if (is_same<T, IndustrialProduct>::value) {
        cout << "==================== Filling an Industrial Products' range ====================" << endl;
        while (true) {
            cout << ">>>================= Adding a new Industrial Product ====================" << endl;

            add_product(T::create_by_user_input());

            cout << "\n==>> Would you like to add another Industrial Product?" << endl;
            cout << "==>> Enter '1' to add or any key to exit..." << endl;

            if (getch() == '1') {
                ProductsInput::draw_line();
            } else {
                break;
            }
        }
    } else {
        throw (invalid_argument("Invalid type for filling."));
    }
}