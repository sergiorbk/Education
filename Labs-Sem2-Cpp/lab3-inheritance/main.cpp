#include "ProductsInput.h"
#include "IndustrialProduct.h"
#include "FoodProduct.h"
#include "ProductList.h"
#include "ProductsOutput.h"
#include <iostream>
using namespace std;

int main() {
    ProductsInput productsInput;
    //ProductsOutput productsOutput;
    while(true){
        ProductList<FoodProduct> foodProductsList;
        foodProductsList.fill_list();
        cout << endl;
        ProductsOutput::print_food_products_list(foodProductsList);
        cout << endl;

        Date inspection_date = productsInput.get_inspection_date();
        float spoiled_food_products_cost = foodProductsList.count_spoiled_products_cost(inspection_date);
        cout << "Total spoiled products' price is: " << spoiled_food_products_cost << endl;
        cout << endl;

        ProductList<IndustrialProduct> industrialProductsList;
        industrialProductsList.fill_list();
        cout << endl;
        ProductsOutput::print_industrial_products_list(industrialProductsList);
        cout << endl;

        float industrial_products_cost_located_at_warehouse = industrialProductsList.count_products_cost_by_location(IndustrialProduct::WAREHOUSE);
        cout << endl;
        cout << "Total industrial products' that located at WAREHOUSE price is: " << industrial_products_cost_located_at_warehouse << endl;
        cout << endl;

        if(ProductsInput::is_exit()){
            break;
        }else{
            system("cls");
        }
    }
    return 0;
}