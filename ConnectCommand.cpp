#include "ConnectCommand.h"
#include "ReadLines.h"


/* setParams : gets a vector of params and sets to params */
void ConnectCommand::setParams(vector<string> params) {
    // if there is no 2 params, error
    if (params.size() != 2) {
        printf("Connect command requires 2 parameters");
        return;
    }
    ReadLines readLines;
    // evaluate expression of second parameter
    params[1] = readLines.negativeNumberToMinus(params[1]);
    portno = readLines.calculateExpressionFromQueue(readLines.shuntingYard(params[1]));
    // convert ip string to char*
    ip = params[0].c_str();
}


void ConnectCommand::execute() {

    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        //  error("ERROR opening socket");
    }

    server = gethostbyname(ip);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
        (char *)&serv_addr.sin_addr.s_addr,
        server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        //error("ERROR connecting");
    }

    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0) {
        //error("ERROR reading from socket");
    }

    printf("%s\n", buffer);
    // close(sockfd);


}
