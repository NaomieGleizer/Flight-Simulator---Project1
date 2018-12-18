#pragma once
#include <string>
#include <vector>

using namespace std;

class Command {
public:
    virtual void execute(vector<string> params) = 0;
};