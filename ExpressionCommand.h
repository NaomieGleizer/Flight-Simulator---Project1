#pragma once

#include "Expression.h"
#include "Command.h"

class ExpressionCommand : public Expression {
    Command* command;
    vector<double> params;
public:
    ExpressionCommand(Command* command);
    Command* getCommand();
    double calculate() override;
};
