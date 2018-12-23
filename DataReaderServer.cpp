#include "DataReaderServer.h"


DataReaderServer::DataReaderServer() {
    // create a socket
    // socket(int domain, int type, int protocol)
    this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (this->sockfd < 0) {
        // error massage
    }
}

void DataReaderServer::openDataServer(int port, int hz) {
    int newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    // clear address structure
    bzero((char *)&serv_addr, sizeof(serv_addr));


    portno = port;


    /* setup the host_addr structure for use in bind call */
    serv_addr.sin_family = AF_INET;

    // automatically be filled with current host's IP address
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    // convert short integer value for port must be converted into network byte order
    serv_addr.sin_port = htons(portno);

    // bind  the socket to the current IP address on port, portno
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0) {
        // error massage
    }


    // listen to the incoming connections.
    // Here, we set the maximum size for the backlog queue to 5.
    listen(sockfd, 5);

    // accepts an incoming connection
    clilen = sizeof(cli_addr);

    // write the connecting client's address info into the the address structure
    // and the size of that structure is clilen.
    newsockfd = accept(sockfd,
                       (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
        // error massage
    }

    bzero(buffer, 256);

    n = read(newsockfd, buffer, 255);
    if (n < 0)  {
        // error massage
    }

    //close(newsockfd);
   // close(sockfd);
   // pthread_exit(NULL);

}






void DataReaderServer::closeDataServer() {
    // close socket
    close(sockfd);
}