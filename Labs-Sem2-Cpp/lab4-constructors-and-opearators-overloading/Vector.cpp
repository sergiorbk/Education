#include "Vector.h"

// a default constructor
//Vector::Vector() : dimension(0), coordinates(nullptr) {}

// a constructor with dimension only
Vector::Vector(const int& dimension) : dimension(dimension), coordinates(new double[dimension]) {}

Vector::Vector(const string& name) : name(name) {}

// a constructor with all parameters
Vector::Vector(const string& name, const int& dimension, double* values) : name(name), dimension(dimension), coordinates(new double[dimension]) {
    for (int i = 0; i < dimension; i++) {
        this->coordinates[i] = values[i];
    }
}

// a copying constructor
Vector::Vector(const Vector& vector_to_copy_from){
    name = vector_to_copy_from.name;
    dimension = vector_to_copy_from.dimension;
    //coordinates = vector_to_copy_from.coordinates;
    for(int i=0; i<dimension; i++){
        coordinates[i] = vector_to_copy_from.coordinates[i];
    }
}

// a destructor
Vector::~Vector() {
    dimension = 0;
    delete[] coordinates;
}

// overloading + operator
Vector Vector::operator+(const Vector& other) const {
    if (dimension != other.dimension) {
        throw std::invalid_argument("Dimensions of vectors must match");
    }
    Vector result(dimension);
    for (int i = 0; i < dimension; i++) {
        result.coordinates[i] = coordinates[i] + other.coordinates[i];
    }
    return result;
}

// overloading * operator
double Vector::operator*(const Vector& other) const {
    if (dimension != other.dimension) {
        throw invalid_argument("Dimensions of vectors must match");
    }
    double result = 0;
    for (int i = 0; i < dimension; i++) {
        result += coordinates[i] * other.coordinates[i];
    }
    return result;
}

// overloading = operator
Vector Vector::operator=(const Vector& other){
    dimension = other.dimension;
    coordinates = new double [dimension];
    for(int i=0; i < other.dimension; i++){
        coordinates[i] = other.coordinates[i];
    }
}

string Vector::get_name() const{
    return name;
}

void Vector::set_name(const string& input_name) {
    name = input_name;
}

int Vector::get_dimension() const {
    return dimension;
}

double Vector::get_coordinate(int index) const {
    if(index > dimension || index <= 0){
        throw invalid_argument("Index is out of range");
    }
    return coordinates[index-1];
}

double Vector::length() const {
    double result = 0;
    for (int i = 0; i < dimension; i++) {
        result += coordinates[i] * coordinates[i];
    }
    return std::sqrt(result);
}