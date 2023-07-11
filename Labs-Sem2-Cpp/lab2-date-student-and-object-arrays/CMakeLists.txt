cmake_minimum_required(VERSION 3.24)
project(lab32)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab32 main.cpp Date.cpp FullName.cpp Group.cpp Student.cpp StudentsArray.cpp StudentsFactory.cpp StudentsFactory.h)
