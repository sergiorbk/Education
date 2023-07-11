#pragma once

#include <stdexcept>
#include <cmath>

ref class Function {
private:
    double x = 0;

public:
    // constructors
    Function() {};
    Function(double x) : x(x) {}

    // methods
    void SetX(double value);
    double Calculate();
};
