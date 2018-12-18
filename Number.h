#pragma once
#include "Expression.h"

class Number : public Expression {
    double value;
public:
    double calculate() {
        return value;
    }
};