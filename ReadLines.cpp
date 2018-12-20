#include "ReadLines.h"
#include <stack>
#include <deque>
#include "Power.h"
#include "Minus.h"
#include "Plus.h"
#include "Multiplication.h"
#include "Division.h"
#include "Number.h"

map<char, int> operators = { { '^', 4 },{ '/', 3 },{ '*', 3 },{ '+', 2 },{ '-', 2 } };
map<string, Expression> commands = {
    { "openDataServer", ExpressionCommand(new OpenDataServerCommand()) }//,
    //{"connect", ExpressionCommand(new ConnectCommand())}
};

map<string, double> symbolTbl;

/*
*   The function gets a string which is a command line from the user and seperates it.
*/
vector<string> ReadLines::lexer(string line) {
    vector<string> splittedStrings;
    string::iterator it = line.begin();
    string command = "";
    while (*it != 32 && *it != 9) { // command (first word)
        command += *it;
        it++;
    }
    splittedStrings.push_back(command);

    string param = "";
    char last = 0;
    while (it != line.end()) {
        if (param.size() != 0) {
            last = param.at(param.size() - 1); // last character inserted
        }
        if (*it == 32 || *it == 9) { // if it's a space or a tab, check if it's the end of the parameter
            if (operators.count(last) == 0 && param != "") {
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
    splittedStrings.push_back(param);
    return splittedStrings;
}

void ReadLines::parser(vector<string> line) {
    vector<double> params;

    if (commands.count(line[0]) == 0) { // chek if the command exists
        return;
    }
    Expression expCommand = commands[line[0]];

    for (int i = 1; i <= line.size() - 1; i++) { // for each parameter
        deque<string> queue = shuntingYard(line[i]);
        Expression param = expressionFromString(queue);
        params.push_back(param.calculate());
    }
    //expCommand.setParams(params);
    expCommand.calculate();
}

Expression ReadLines::expressionFromString(deque<string> queue) {
    if (queue.size() == 1) {
        return Number((double)(stoi(queue.back())));
    }

    string s = queue.back();
    Number leftNumber((double)(stoi(queue.front())));
    queue.pop_back();
    queue.pop_front();

    if (s.compare("^") == 0) {
        return Power(leftNumber, expressionFromString(queue));
    }

    else if (s.compare("*") == 0) {
        Expression e = expressionFromString(queue);
        return Multiplication(leftNumber, e);
    }

    else if (s.compare("/") == 0) {
        return Division(leftNumber, expressionFromString(queue));
    }

    else if (s.compare("+") == 0) {
        return Plus(leftNumber, expressionFromString(queue));
    }

    else if (s.compare("*") == 0) {
        return Minus(leftNumber, expressionFromString(queue));
    }
    else {
        return Number((double)(stoi(queue.back())));
    }

}

deque<string> ReadLines::shuntingYard(string expression) {
    stack<char> stack;
    deque<string> queue;
    string::iterator it = expression.begin();
    char topStack;
    string currentNumber = "";
    while (it != expression.end()) { // while there are tokens to be read

        if (*it == '(') {
            stack.push(*it);
        }

        else if (operators.count(*it)) { // if it's an operator
            if (!stack.empty()) {
                topStack = stack.top();
                while (operators[topStack] > operators[*it]) { // while there's an operator at top of the stack with greater precedence
                    stack.pop();               // pop operator from stack
                    queue.push_back(string(1, topStack)); // push it to the queue
                    topStack = stack.top();
                }
            }
            stack.push(*it);
        }

        else if (*it == ')') {
            while (stack.top() != '(') { // while there's not a '(' at the top of the stack
                queue.push_back(string(1, stack.top())); // push it to the queue
                stack.pop();                  // pop operator from stack

            }
            stack.pop(); // pop the '('
        }

        else { // it is a number
            currentNumber += *it;
            while ((++it)!= expression.end()&& *it >= 48 && *it <= 57) { // while the char is a number
                currentNumber += *it;
         
            }
            queue.push_back(currentNumber);  // push the number to queue
            currentNumber = "";
            it--;
        }

        it++;
    }
    // there's no more token to be read
    while (!stack.empty()) { // while there's an operator at the top of the stack
        queue.push_back(string(1, stack.top())); // push it to the queue
        stack.pop();                  // pop operator from stack
    }
    return queue;
}