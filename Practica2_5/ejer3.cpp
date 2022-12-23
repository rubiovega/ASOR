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
using namespace std;

int main(int argc, char **argv)
{
    struct addrinfo hints;
    struct addrinfo * result;
    memset(&hints, 0, sizeof(struct addrinfo));

    hints.ai_flags = AI_PASSIVE;
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;

    int rc = getaddrinfo(argv[1],argv[2],&hints,&result);

    if (rc != 0)
    {
        cout << "[getaddrinfo]: " << strerror(errno) << endl;
        exit(EXIT_FAILURE);
    }

    int sd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

    freeaddrinfo(result);

    struct sockaddr_storage client_addr;
    socklen_t client_addrlen = sizeof(client_addr);

    sendto(sd, argv[3], 2, 0, result->ai_addr, result->ai_addrlen);

    if (*argv[3] == 'd' || *argv[3] == 't')
    {
        char m[50];
        size_t bytes = recvfrom(sd,m,50,0,(struct sockaddr *) &client_addr, &client_addrlen);
        m[bytes] = '/0';
        cout << m << endl;

    }

    return 0;
}
    