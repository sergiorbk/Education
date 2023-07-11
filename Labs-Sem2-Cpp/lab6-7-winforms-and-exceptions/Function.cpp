#include "Function.h"

void Function::SetX(double value) {
    x = value;
}

double Function::Calculate() {
    if (x == 2) {
        throw std::invalid_argument("Argument x cannot be equal to 2");
    }
    else {
        return std::abs((std::abs(x - 2) + 1) / (x - 2));
    }
}