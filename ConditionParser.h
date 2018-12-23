#pragma once
#include "Command.h"
#include <list>

class ConditionParser : public Command {
protected:
    list<Command*> commands;
    vector<string> condition;
public:
    //ConditionParser()
};