cmake_minimum_required(VERSION 3.24)
project(overloading)

set(CMAKE_CXX_STANDARD 17)

add_executable(overloading main.cpp Vector.h InputHandler.h OutputHandler.h Activity.cpp Activity.h InputHandler.cpp OutputHandler.cpp Vector.cpp)
