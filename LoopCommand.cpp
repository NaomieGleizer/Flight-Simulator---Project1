#include "LoopCommand.h"
#include "ReadLines.h"

bool LoopCommand::conditionSatisfied() {
    /* condition in params. for example: alt < 5
       get the variable (alt)
       check the condition */
    return true;
}

/*
*/
void LoopCommand::setParams(vector<string> params) {
    ReadLines readLines;
    vector<string> line;
    vector<string>::iterator it = params.begin();
    while (it != params.end()) {
        while (readLines.isInMapCommands(*it)) {
            line.push_back(*it);
            it++;
        }
        linesCommand.push_back(line);
        line.clear();
        it++;
    }
}

void LoopCommand::execute() {
    ReadLines readLines;
    while (!conditionSatisfied()) {
        for (vector<string> line : linesCommand) {
            readLines.parser(line); // parser will execute the line
        }
    }
}


