#pragma once
#include "Command.h"

class ConnectCommand : public Command {
public:
    void execute();
    void setParams(vector<double> params);

};