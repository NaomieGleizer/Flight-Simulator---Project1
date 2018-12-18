#include "OpenDataServerCommand.h"
#include <thread>

 void OpenDataServerCommand::execute(vector<string> params) {

        if (params.size() != 2) {
            printf("Open data server command requires 2 parameters");
            return;

        }

        int port = stoi(params[0]);
        int hz = stoi(params[1]);
        //thread t = openServer(port, hz);
    
}