#include "ExpressionCommand.h"

ExpressionCommand::ExpressionCommand(Command* command) {
    this->command = command;
}

double ExpressionCommand::calculate() {
    command->execute();
    return 1.0;
}

Command* ExpressionCommand::getCommand() {
    return command;
}

