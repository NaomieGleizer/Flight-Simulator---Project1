#include "Multiplication.h"

Multiplication::Multiplication(Expression* left, Expression* right) : BinaryExpression(left, right) {};

double Multiplication::calculate() {
    return (*left).calculate() * (*right).calculate();
}
