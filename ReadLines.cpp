#include "ReadLines.h"
#include <sstream>
#include <iostream>

/*
*   The function gets a string which is a command line from the user and seperates it.
*/
vector<string> ReadLines::lexer(string line) {
    vector<string> splittedStrings;
    string::iterator it = line.begin();
    string command="";
    while (*it != 32 && *it != 9) { // command (first word)
        command += *it;
    }
    splittedStrings.push_back(command);

    string param = "";
    char last=0;
    while (it != line.end()) {
        if (param.size() != 0) {
            last = param.at(param.size() - 1); // last character inserted
        }
        if (*it == 32 || *it == 9) { // if it's a space or a tab, check if it's the end of the parameter
            if (last != '+' && last != '-' && last != '*' && last != '/') {
                // end of parameter
                splittedStrings.push_back(param); // insert the parameter to the vector
                param = ""; // new parameter
                last = 0;
            }
            it++;
            continue;
        }
        param += *it; // add char to the current parameter
        it++;
    }

    return splittedStrings;
}

void ReadLines::parser(vector<string> line) {
    if (commands.count(line[0]) == 0) {
        return;
    }
    Expression e = commands[line[0]];
    line.erase(line.begin());
    e.calculate();
}