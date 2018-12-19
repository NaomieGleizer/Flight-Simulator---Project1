#pragma once
#include "BinaryExpression.h"

class Multiplication : public BinaryExpression {
public:
    Multiplication(Expression left, Expression right);

    double calculate() override;
};
