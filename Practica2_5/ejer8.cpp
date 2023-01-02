#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <iostream>
#include <errno.h>
using namespace std;

#define BUF_SIZE 500

int main(int argc, char **argv)
{
    struct addrinfo hints;
    struct addrinfo *result;
    int sfd,rc,clisd;
    struct sockaddr_storage addr;
    socklen_t addr_len;
    ssize_t nread;
    char buf[BUF_SIZE];

    if (argc != 3) 
    {
        exit(EXIT_FAILURE);
    }

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;    
    hints.ai_socktype = SOCK_STREAM; 
    hints.ai_flags = 0;

    rc = getaddrinfo(argv[1], argv[2], &hints, &result);
    if (rc != 0) 
    {
        cout << "[getaddrinfo]: " << strerror(errno);
        exit(EXIT_FAILURE);
    }

    sfd = socket(i->ai_family, i->ai_socktype,
                        i->ai_protocol);

    rc = bind(sfd, i->ai_addr, i->ai_addrlen);
    if (rc != 0) 
    {
        cout << "[bind]: " << strerror(errno);
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(result); 

    listen (sfd,5);

    char host[NI_MAXHOST],serv[NI_MAXSERV];

    while (1)
    {
        addr_len = sizeof(addr);
        clisd = accept(sfd,(struct sockaddr *) &addr, &addr_len);

        pid_t pid = fork();

        if (pid == 0)
        {
            while (1)
            {
                rc = getnameinfo((struct sockaddr *) &addr,
                                    addr_len, host, NI_MAXHOST,
                                    serv, NI_MAXSERV, NI_NUMERICSERV);

                if (rc != 0) 
                {
                    cout << "[getnameinfo]: " << strerror(errno);
                    exit(EXIT_FAILURE);
                }

                cout << "[PID: " << getpid() << "Conexion desde " << host << ":" << serv << endl;
    
                nread = recv(clisd,buf,80,0);
                buf[nread]='/0';

                if ((buf[0] == 'Q') && (nread == 2)) 
                {
                    printf("Conexión terminada\n");
                    break;
                }

                send(clisd,buf,nread,0);

            }
            
        }
    }
     close(clisd);
}