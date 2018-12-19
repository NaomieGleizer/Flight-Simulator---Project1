#pragma once
#include "Expression.h"

class Number : public Expression {
    double value;
public:
    Number(double number);
    double calculate();
};