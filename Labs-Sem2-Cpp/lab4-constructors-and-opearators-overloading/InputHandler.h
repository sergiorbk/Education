#ifndef OVERLOADING_INPUTHANDLER_H
#define OVERLOADING_INPUTHANDLER_H


#include <string>
#include "Vector.h"
using namespace std;

class InputHandler {
public:
    static string get_name();
    static int get_dimension();
    static double* get_coordinates(int dimension);
    static Vector init_vector();
};


#endif //OVERLOADING_INPUTHANDLER_H
