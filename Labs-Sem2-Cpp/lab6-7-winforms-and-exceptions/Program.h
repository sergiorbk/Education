#pragma once
#include "Function.h"
#include <Windows.h>
#include <cmath>
using namespace System::Windows::Forms;
using namespace System;

ref class Program {
public:
    static void Calculate(double intervalBegin, double intervalEnd, double xStep, Function^ function, ListBox^ answersListBox);
};