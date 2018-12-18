#pragma once
#include <string>
#include <vector>
#include <map>
#include "Expression.h"
#include "E"

using namespace std;

map<string, Expression> commands = {("openDataServer", newE)};

class ReadLines {

public:
    vector<string> lexer(string line);
    void parser(vector<string> line);
};
