#pragma once
#include "Command.h"
#include "DataReaderServer.h"

class OpenDataServerCommand : public Command {
    vector<int> params;
    pthread_t* t;
    // struct of params to data reader server : port, hz

public:
    OpenDataServerCommand(pthread_t* t);
    void execute();
    void setParams(vector<string> params);
    pthread_t* threadID();
    //struct MyParams* getParamsOfThread();
};