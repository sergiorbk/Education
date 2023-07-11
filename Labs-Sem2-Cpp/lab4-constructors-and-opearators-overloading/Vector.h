#ifndef OVERLOADING_VECTOR_H
#define OVERLOADING_VECTOR_H

#include <iostream>
#include <cmath>
using namespace std;
//class  Point
class Point2D {
    //operators
};
class Point3D : public Point2D  { // Open close principle

};

class Vector {
private:
    string name;
    int dimension;
    double* coordinates;
    // AbstractPoint
    // GOF patterns (creation patterns)
    // injection of control -> DI  (ctor injection)
    // a constructor with dimension only
    Vector(const int& dimension);

public:
    // a default constructor
    //Vector();

    // a constructor with name only
    Vector(const string& name);

    // a constructor with all parameters
    Vector(const string& name, const int& dimension, double* values);

    // a copying constructor
    Vector(const Vector& vector_to_copy_from);

    // a destructor
    ~Vector();

    // overloading + operator
    Vector operator+(const Vector& other) const;

    // overloading * operator
    double operator*(const Vector& other) const;

    // overloading = operator
    Vector operator=(const Vector& other);

    string get_name() const;
    void set_name(const string& input_name);
    int get_dimension() const;
    double get_coordinate(int index) const;
    double length() const;

};


#endif //OVERLOADING_VECTOR_H
