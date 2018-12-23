#pragma once
#include "Command.h"
#include <list>

class ConditionParser : public Command {
protected:
    list<vector<string>> linesCommand;
    vector<string> condition;
public:
    //ConditionParser()
};