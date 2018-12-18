#pragma once
#include "Command.h"

class OpenDataServerCommand : public Command {

public:
    void execute(vector<string> params);
};