cmake_minimum_required(VERSION 3.24)
project(lab4_5_inheritance)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab4_5_inheritance main.cpp Product.cpp Product.h Date.cpp IndustrialProduct.cpp IndustrialProduct.h
        FoodProduct.cpp FoodProduct.h  ProductsInput.h  ProductsInput.cpp ProductList.tpp ProductList.h ProductsOutput.cpp ProductsOutput.h)