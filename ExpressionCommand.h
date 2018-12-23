#pragma once

#include "Expression.h"
#include "Command.h"

class ExpressionCommand : public Expression {
    Command* command;
    vector<double> params;
public:
    ExpressionCommand(Command* command);
    void setParams(vector<string> params);
    double calculate() override;
    Command* getCommand();
};
