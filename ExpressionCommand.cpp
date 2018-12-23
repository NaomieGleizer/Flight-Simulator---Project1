#include "ExpressionCommand.h"

ExpressionCommand::ExpressionCommand(Command* command) {
    this->command = command;
}

double ExpressionCommand::calculate() {
    command->execute();
    return 0;
}

void ExpressionCommand::setParams(vector<string> params) {
    command->setParams(params);
}

Command* ExpressionCommand::getCommand() {
    return command;
}

