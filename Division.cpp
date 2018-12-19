#include "Division.h"

Division::Division(Expression left, Expression right) : BinaryExpression(left, right) {};

double Division::calculate() {
    return left.calculate() / right.calculate();
}
