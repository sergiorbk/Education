#include "InputHandler.h"
#include <iostream>
#include "Vector.h"

string InputHandler::get_name(){
    string name;
    cout << "==>> Enter vector's name: "; cin >> name;
    return name;
}

int InputHandler::get_dimension(){
    int dimension;
    do{
        cin.clear();
        cin.ignore();
        cout << "==>> Enter dimension: "; cin >> dimension;
    }while(cin.fail());
    return dimension;
}

double* InputHandler::get_coordinates(int dimension){
    auto coordinates = new double[dimension]; // type double*
    for(int i=0; i < dimension; i++){
        double coordinate;
        do{
            cin.clear();
            cin.ignore();
            cout << "==>> Enter coordinate " << i+1 << ": "; cin >> coordinate;
        }while(cin.fail());
        coordinates[i] = coordinate;
    }
    cout << endl;
    return coordinates;
}

Vector InputHandler::init_vector(){
    cout << "==>> Creating new vector >>>>>>>>>>" << endl;
    string name = get_name();
    int dimension = get_dimension();
    double* coordinates = get_coordinates(dimension);
    cout << "====================================" << endl;
    return Vector(name, dimension, coordinates);
}