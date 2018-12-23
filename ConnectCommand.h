#pragma once
#include "Command.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

class ConnectCommand : public Command {
    int portno;
    const char* ip;
public:
	void execute();
	void setParams(vector<string> params);

};