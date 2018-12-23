#include "OpenDataServerCommand.h"
#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
struct MyParams
{
    int port;
    int hz;
};

OpenDataServerCommand::OpenDataServerCommand(pthread_t* t) {
    this->t = t;
}

pthread_t* OpenDataServerCommand::threadID() {
    return this->t;
}

/* setParams : gets a vector of params and sets to params */
void OpenDataServerCommand::setParams(vector<string> params) {
    if (params.size() != 2) {
        printf("Open data server command requires 2 parameters");
        return;

    }
    ReadLines readLines;
    for (int i = 0; i <= 1; i++) {
        params[i] = readLines.negativeNumberToMinus(params[i]); // take care of negative numbers 
        deque<string> queue = readLines.shuntingYard(params[i]); // get a queue from shunting-yard 
        this->params.push_back((int)readLines.calculateExpressionFromQueue(queue)); // calculate the expression and add to params
    }
}

/* openDataServerThread : thread that opens a data reader server with the given args */
void* openDataServerThread(void* arg)
{
    DataReaderServer readerServer = DataReaderServer();
    struct MyParams* args = (struct MyParams*) arg;
    // opens data reader server
    readerServer.openDataServer(args->port, args->hz);
}

/* execute : opens data server */
void OpenDataServerCommand::execute() {
    // set port and hz to struct of my params
    struct MyParams* arg = new MyParams();
    arg->port = params[0];
    arg->hz = params[1];
    // create thread for opening data server
    pthread_create(this->t, nullptr, openDataServerThread, arg);

}