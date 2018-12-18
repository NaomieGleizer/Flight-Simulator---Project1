#pragma once
#include "Expression.h"

class BinaryExpression : public Expression {
protected:
    Expression left;
    Expression right;
public:
    BinaryExpression(Expression left, Expression right) {
        this->left = left;
        this->right = right;
    }

};
