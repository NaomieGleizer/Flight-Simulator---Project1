#pragma once
#include <string>
#include <vector>
#include <map>
#include "Expression.h"
#include "ExpressionCommand.h"
#include "OpenDataServerCommand.h"

using namespace std;

map<string, Expression> commands = { {"openDataServer", new ExpressionCommand(new OpenDataServerCommand())} };

class ReadLines {

public:
    vector<string> lexer(string line);
    void parser(vector<string> line);
};
