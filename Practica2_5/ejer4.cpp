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
#include <algorithm> 
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
    
    rc = bind(sd, (struct sockaddr *) result->ai_addr, result->ai_addrlen);

        if (rc!=0)
    {
        cout << "[bind]: " << strerror(errno) << endl;
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(result);

    fd_set fdset;

    struct sockaddr_storage client_addr;
    socklen_t client_addrlen = sizeof(client_addr);
    char buf[2];
    char host[NI_MAXHOST];
    char serv[NI_MAXSERV];
        
    while(1)
    {
        char mensaje[100];
        size_t bytesSend;
        time_t t;
        time(&t);
        size_t max;
        struct tm *lt = localtime(&t);
        FD_ZERO(&fdset);
        FD_SET(0,&fdset);
        FD_SET(sd, &fdset);
        select(sd+1,&fdset,NULL,NULL,NULL);

        if (FD_ISSET(0, &fdset))
        {
            cout << "Comando recibido de la entrada standar" << endl;
            cin >> buf;

            switch(buf[0])
            {
                case 't':
                    bytesSend = strftime(mensaje,max,"%T",lt);
                    break;
                
                case 'd':
                    bytesSend = strftime(mensaje,max,"%F",lt);
                    break;

                case 'q':
                     exit(EXIT_SUCCESS);
                    break;

                default:
                    cout << "Comando " << buf[0] << " no soportado";  
                    strcpy(mensaje, "\n"); 
                    break;

            }
            cout << mensaje << endl;        
        }
        else if (FD_ISSET(sd, &fdset))
         {
            size_t bytes = recvfrom(sd,buf,2,0,(struct sockaddr *) &client_addr, &client_addrlen);
            
            getnameinfo((struct sockaddr *) &client_addr, client_addrlen, host , NI_MAXHOST,
            serv, NI_MAXSERV, NI_NUMERICHOST|NI_NUMERICSERV);

            cout << "Recibidos  " << bytes<< " bytes de " << host << ":" << serv << endl;
 
            switch(buf[0])
            {
                case 't':
                    bytesSend = strftime(mensaje,max,"%T",lt);
                    break;
                
                case 'd':
                    bytesSend = strftime(mensaje,max,"%F",lt);
                    break;

                case 'q':
                    exit(EXIT_SUCCESS);
                    break;

                default:
                    strcpy(mensaje,"Comando no soportado");
                    bytesSend = 20;
                    break;

            }
            sendto(sd, mensaje, bytesSend, 0, (struct sockaddr *) &client_addr, client_addrlen);
        }
    }
}
