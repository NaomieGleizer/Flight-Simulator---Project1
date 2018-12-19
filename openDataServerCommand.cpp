#include "OpenDataServerCommand.h"
#include <thread>


void OpenDataServerCommand::setParams(vector<double> params) {
    this->params = params;
}

 void OpenDataServerCommand::execute() {

        if (params.size() != 2) {
            printf("Open data server command requires 2 parameters");
            return;

        }

        double port = params[0];
        double hz = params[1];
        //thread t = openServer(port, hz);
    
}