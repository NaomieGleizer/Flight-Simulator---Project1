#include "ExpressionCommand.h"

ExpressionCommand::ExpressionCommand(Command* command) {
    this->command = command;
}

double ExpressionCommand::calculate() {
    command->execute();
}
