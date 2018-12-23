#pragma once
#include <string>
#include <vector>

using namespace std;

class Command {
public:
    virtual void execute() = 0;
    virtual void setParams(vector<string> params) = 0;
};