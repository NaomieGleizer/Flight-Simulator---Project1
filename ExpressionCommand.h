#pragma once

#include "Expression.h"
#include "Command.h"

class ExpressionCommand : public Expression {
    Command* command;
public:
    ExpressionCommand(Command* command);

    double calculate();
};
