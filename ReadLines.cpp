#include "ReadLines.h"
#include <stack>
#include <deque>
#include "Power.h"
#include "Minus.h"
#include "Plus.h"
#include "Multiplication.h"
#include "Division.h"
#include "Number.h"

map<string, int> operators = { { "^", 4 },{ "/", 3 },{ "*", 3 },{ "+", 2 },{ "-", 2 } };
map<string, ExpressionCommand*> commands = {
    { "openDataServer", new ExpressionCommand(new OpenDataServerCommand()) }//,
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
    bool isComma = false;
    while (it != line.end()) {
        if (param.size() != 0) {
            last = param.at(param.size() - 1); // last character inserted
        }
        if (*it == 32 || *it == 9 || (*it) == ',') { // if it's a space or a tab, check if it's the end of the parameter
            if ((*it) == ',') { // flag for end of current parameter
                isComma = true;
            }
            it++; // skip char
            // if last char wasn't an operator or current char isn't an operator, or if there is a comma
            if ((operators.count(string(1, last)) == 0 && operators.count(string(1, *it)) == 0 && param != "") || isComma) {
                // end of parameter
                splittedStrings.push_back(param); // insert the parameter to the vector
                param = ""; // new parameter
                last = 0;
            }
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
    ExpressionCommand* expCommand = commands[line[0]];

    for (int i = 1; i <= line.size() - 1; i++) { // for each parameter
        // take care of negativr numbers in the parameter
        line[i] = negativeNumberToMinus(line[i]);
        deque<string> queue = shuntingYard(line[i]);
        double param = expressionFromString(queue);
        params.push_back(param);
    }
    expCommand->setParams(params);
    (*expCommand).calculate();
}

/*
* Change the negative number in the expression to 0-x.
* For example: -3+4 -> (0-3)+4.   9*-8 -> 9*(0-8).  6+(-4) -> 6+(0-4)
*/
string ReadLines::negativeNumberToMinus(string line) {
    string::iterator it = line.begin();
    string minus0 = "";
    char last = 0;
    while (it != line.end()) {
        if ((*it) == '-' && (last == 0 || operators.count(string(1, last)) || last == '(')) {
            if (last == '(') {
                minus0 = "0";
                line.insert(it, minus0.begin(), minus0.end());
                it += 3; // skip the '-', the number and the ')'
            }
            else {
                minus0 = "(0";
                line.insert(it, minus0.begin(), minus0.end());
                it += 4; // skip the '(', the 0, the '-' and the number
                minus0 = ")";
                line.insert(it, minus0.begin(), minus0.end());
            }
        }
        last = *it;
        it++;
    }
    return line;
}

double ReadLines::expressionFromString(deque<string> queue) {
    if (queue.size() == 1) { // end of function, resault in queue
        return stod(queue.front());
    }
    string last, op;
    double first, second;
    deque<string>::iterator it = queue.begin();
    while (operators.count(*it) == 0) { // skip while it's not an operator
        it++;
    }
    // take 2 numbers before operator
    first = stod(*(it - 2)); 
    second = stod(*(it - 1));
    // delete them from queue
    it=queue.erase(it - 1);
    it = queue.erase(it - 1);
    op = *it; // save operator
    it = queue.erase(it); // delete operator from queue
    // calculate with 2 numbers, push result to queue
    if (op.compare("+") == 0) {
        queue.push_front(to_string(first + second));
    }
    else if (op.compare("-") == 0) {
        queue.push_front(to_string(first - second));
    }
    else if (op.compare("*") == 0) {
        queue.push_front(to_string(first * second));
    }
    else if (op.compare("/") == 0) {
        queue.push_front(to_string(first / second));
    }
    else if (op.compare("^") == 0) {
        queue.push_front(to_string(pow(first, second)));
    }
    return expressionFromString(queue); // continue with new queue
}



deque<string> ReadLines::shuntingYard(string expression) {
    stack<string> stack;
    deque<string> queue;
    string::iterator it = expression.begin();
    string topStack, currentNumber = "", currentChar;
    while (it != expression.end()) { // while there are tokens to be read
        currentChar = string(1, *it);
        if (*it == '(') {
            stack.push(currentChar);
        }

        else if (operators.count(currentChar)) { // if it's an operator
            if (!stack.empty()) {
                topStack = stack.top();
                if (topStack != "(") {

                    while (operators[topStack] > operators[currentChar]) { // while there's an operator at top of the stack with greater precedence
                        stack.pop();               // pop operator from stack
                        queue.push_back(topStack); // push it to the queue
                        if (stack.empty()) {
                            break;
                        }
                        topStack = stack.top();
                    }
                }
            }
            stack.push(currentChar);
        }

        else if (*it == ')') {
            while (stack.top() != "(") { // while there's not a '(' at the top of the stack
                queue.push_back(stack.top()); // push it to the queue
                stack.pop();                  // pop operator from stack

            }
            stack.pop(); // pop the '('
        }

        else { // it is a number
            currentNumber += *it;
            while ((++it) != expression.end() && *it >= 48 && *it <= 57) { // while the char is a number
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
        queue.push_back(stack.top()); // push it to the queue
        stack.pop();                  // pop operator from stack
    }
    return queue;
}