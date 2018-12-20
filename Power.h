#pragma once
#include "BinaryExpression.h"

class Power : public BinaryExpression {
public:
    Power(Expression* left, Expression* right);

    double calculate();
};