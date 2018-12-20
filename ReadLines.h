#pragma once
#ifndef READLINES_H
#define READLINES_H

#include <string>
#include <vector>
#include <map>
#include <deque>
#include "Expression.h"
#include "ExpressionCommand.h"
#include "OpenDataServerCommand.h"
#include "ConnectCommand.h"

using namespace std;



class ReadLines {

public:
    vector<string> lexer(string line);
    void parser(vector<string> line);
    deque<string> shuntingYard(string expression);
    Expression* expressionFromString(deque<string> queue);
};

#endif 

