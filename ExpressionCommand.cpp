#include "ExpressionCommand.h"

ExpressionCommand::ExpressionCommand(Command* command) {
    this->command = command;
}

double ExpressionCommand::calculate() {
    command->execute();
    return 0;
}

void ExpressionCommand::setParams(vector<double> params) {
    command->setParams(params);
}

