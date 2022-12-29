#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <iostream>
#include <string.h>
#include <stdlib.h> 
using namespace std;

int main(int argc, char **argv)
{
    //./ejer1 <dir> <port>
    if (argc != 3) 
    {
        exit(EXIT_FAILURE);
    }

    struct addrinfo hints;
    struct addrinfo * result;
    memset(&hints, 0, sizeof(struct addrinfo));

    hints.ai_flags = AI_PASSIVE;
    hints.ai_family = AF_UNSPEC;

    int rc = getaddrinfo(argv[1],NULL,&hints,&result);

    if (rc!=0)
    {
        cout << "[getaddrinfo]: " << gai_strerror(rc) << endl;
        return -1;
    }

    for (struct addrinfo *i = result; i!=0; i = i->ai_next)
    {
        char host[NI_MAXHOST];
        char serv[NI_MAXSERV];

        getnameinfo(i->ai_addr, i->ai_addrlen, host, NI_MAXHOST, serv, NI_MAXSERV, 
                    NI_NUMERICHOST);

        cout << host << " " << i->ai_family << " " << i->ai_socktype << endl;
    }

    return 0;
}