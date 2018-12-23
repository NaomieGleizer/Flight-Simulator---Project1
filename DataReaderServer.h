#ifndef DATAREADERSERVER_H
#define DATAREADERSERVER_H

#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

class DataReaderServer {
    int sockfd;
public:
    DataReaderServer();
    void openDataServer(int port, int hz);
    void closeDataServer();
};

#endif
