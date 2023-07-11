#ifndef OVERLOADING_OUTPUTHANDLER_H
#define OVERLOADING_OUTPUTHANDLER_H


#include "Vector.h"
#include <iostream>
#include <conio.h>
using namespace std;

class OutputHandler {
public:
    static void show_coordinates(const Vector& vector);
    static void show_length(const Vector& vector);
    static bool is_exit();
};


#endif //OVERLOADING_OUTPUTHANDLER_H
