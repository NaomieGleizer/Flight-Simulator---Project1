#pragma once
#include "Command.h"

class SetVariableCommand : public Command {
    string var;
public:
    SetVariableCommand(string var);
    void execute();
    void setParams(vector<string> params);
};