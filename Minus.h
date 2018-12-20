#pragma once
#include "BinaryExpression.h"

class Minus : public BinaryExpression {
public:
    Minus(Expression* left, Expression* right);

    double calculate() override;
}; 
