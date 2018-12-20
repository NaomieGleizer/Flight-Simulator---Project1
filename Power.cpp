#include "Power.h"
#include <math.h>

Power::Power(Expression* left, Expression* right) : BinaryExpression(left, right) {};

double Power::calculate() {
    return pow((*left).calculate(),(*right).calculate());
}
