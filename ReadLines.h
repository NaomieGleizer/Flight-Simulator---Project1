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
#include <pthread.h>
#include <thread>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

using namespace std;

class ReadLines {
    pthread_t* t;
    map<string, ExpressionCommand*> expCommands;
    map<string, double> symbolTbl;
public:
    ReadLines() {
        pthread_t trid;
        this->t = &trid;
        expCommands = {
            { "openDataServer", new ExpressionCommand(new OpenDataServerCommand(this->t)) },
            { "connect", new ExpressionCommand(new ConnectCommand()) },
            { "while", new ExpressionCommand(new LoopCommand()) },
        };
    }
    vector<string> lexer(vector<string> lines);
    void parser(vector<string> line);
    deque<string> shuntingYard(string expression);
    double calculateExpressionFromQueue(deque<string> queue);
    string negativeNumberToMinus(string line);
    bool isLoopCommand(string command);
    bool isInMapCommands(string s);
};

#endif 

