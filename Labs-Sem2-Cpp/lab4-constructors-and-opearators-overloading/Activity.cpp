#include "Activity.h"
#include <iostream>
#include "Vector.h"
#include "InputHandler.h"
#include "OutputHandler.h"

void Activity::call(){
    cout << "========== The first vector initialization (full init using copying constructor) ==========" << endl;
    // creating a new vector using copying constructor
    Vector vector1(InputHandler::init_vector());
    cout << endl;

    cout << "========== The second vector initialization (full init using constr. with all param. ) ==========" << endl;
    string vector2_name = InputHandler::get_name();
    int vector2_dimension = InputHandler::get_dimension();
    double* vector2_coordinates = InputHandler::get_coordinates(vector2_dimension);
    // creating a new vector using a constructor with all parameters
    Vector vector2(vector2_name, vector2_dimension, vector2_coordinates);
    cout << endl;

    cout << "========== The third vector initialization (using constructor with name only)==========" << endl;
    Vector vector3(InputHandler::get_name());
    try{
        cout << "==>> Summarizing " << vector1.get_name() << " with " << vector2.get_name() << "..." << endl;
        vector3 = vector1 + vector2;
        OutputHandler::show_coordinates(vector3);
        OutputHandler::show_length(vector3);

        // finding a scalar product of vectors 1 and 3
        cout << "==>> Scalar product of vectors "<< vector1.get_name() << " and " <<
             vector3.get_name() << " equals: " << vector1 * vector3 << endl;
    }catch (invalid_argument& e){
        cout << "==>> Unable to initialize vector 3: " << e.what() << endl;
        cout << endl;
    }

    delete[] vector2_coordinates;
}