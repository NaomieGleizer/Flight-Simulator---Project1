#pragma once
#include <string>
#include <vector>
#include <map>
#include <deque>
#include "Expression.h"
#include "ExpressionCommand.h"
#include "OpenDataServerCommand.h"
#include "ConnectCommand.h"

using namespace std;

map<string, Expression> commands;// = {
    //{"openDataServer", ExpressionCommand(new OpenDataServerCommand())}//,
    //{"connect", ExpressionCommand(new ConnectCommand())}
//};

map<string, double> symbolTbl;

class ReadLines {

public:
    vector<string> lexer(string line);
    void parser(vector<string> line);
    deque<char> shuntingYard(string expression);
    Expression expressionFromString(deque<char> queue);
};
