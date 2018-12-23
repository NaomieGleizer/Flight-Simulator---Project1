#pragma once
#include "ConditionParser.h"

class LoopCommand : public ConditionParser {

public:
    void execute();
    bool conditionSatisfied();
    void setParams(vector<string> params);
};