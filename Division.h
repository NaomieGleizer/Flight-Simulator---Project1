#pragma once
#include "BinaryExpression.h"

class Division : public BinaryExpression {
public:
    Division(Expression left, Expression right);

    double calculate() override;
};