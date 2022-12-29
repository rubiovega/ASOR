#include <sys/socket.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <iostream>
#include <string.h>
#include <errno.h>
#include <stdlib.h>  
#include <stdio.h>
#include <time.h>
#include <unistd.h>
using namespace std;

int main(int argc, char **argv)
{
    //./ejer6 <dir> <port>
    if (argc != 3) 
    {
        exit(EXIT_FAILURE);
    }

    struct addrinfo hints;
    struct addrinfo * result;
    memset(&hints, 0, sizeof(struct addrinfo));

    hints.ai_flags = AI_PASSIVE;
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    int rc = getaddrinfo(argv[1],argv[2],&hints,&result);

    if (rc != 0)
    {
        cout << "[getaddrinfo]: " << strerror(errno) << endl;
        exit(EXIT_FAILURE);
    }

    int sd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

    rc = bind(sd, (struct sockaddr *) result->ai_addr, result->ai_addrlen);

    if (rc!=0)
    {
        cout << "[bind]: " << strerror(errno) << endl;
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(result);

    struct sockaddr_storage client_addr;
    socklen_t client_addrlen = sizeof(client_addr);
    char buf[2];
    char host[NI_MAXHOST];
    char serv[NI_MAXSERV];

    listen(sd,5);

    while(1)
    {
        int clisd = accept(sd, (struct sockaddr *) &client_addr, &client_addrlen);

        getnameinfo((struct sockaddr *) &client_addr, client_addrlen, host , NI_MAXHOST,
        serv, NI_MAXSERV, NI_NUMERICHOST|NI_NUMERICSERV);

        cout << "Conexion  [" << host << ":" << serv << "]" << endl;
        char mensaje[100];
        size_t bytesSend;
        size_t max;
        int c;

        while (c=recv(clisd,buf,80,0))
        {
            send(clisd,buf,c,0);
        }

        cout << "Conexion terminada" << endl;
        close(clisd);

    }

    close(sd);
}