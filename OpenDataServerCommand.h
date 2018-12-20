#pragma once
#include "Command.h"

class OpenDataServerCommand : public Command {
    vector<double> params;
public:
    void execute();
    void setParams(vector<double> params);
};