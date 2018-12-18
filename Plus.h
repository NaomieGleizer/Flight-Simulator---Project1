#pragma once
#include "BinaryExpression.h"

class Plus : public BinaryExpression {
public:
    Plus(Expression left, Expression right);

    double calculate() override {};
};