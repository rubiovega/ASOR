#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <iostream>
using namespace std;

#define BUF_SIZE 500

int main(int argc, char **argv)
{
    //./ejer7 <dir> <port>
    if (argc != 3) 
    {
        exit(EXIT_FAILURE);
    }

    struct addrinfo hints;
    struct addrinfo *result;
    int sfd, rc;
    size_t len;
    ssize_t nread;
    char buf[BUF_SIZE];

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;

    rc = getaddrinfo(argv[1], argv[2], &hints, &result);
    if (rc != 0) 
    {
        cout << "[getaddrinfo]:" << strerror(errno) << endl;
        exit(EXIT_FAILURE);
    }

    sfd = socket(result->ai_family, result->ai_socktype,
                    result->ai_protocol);

    rc = connect(sfd, result->ai_addr, result->ai_addrlen) ;

    if (rc!=0)
    {
        cout << "[connect]: " << strerror(errno) << endl;
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(result);

    while(buf[0] != 'Q'){
		read(0, &buf, 80);
		buf[strlen(buf)] = '\0';

		send(sfd, &buf, strlen(buf), 0);
		recv(sfd, buf,80, 0);
	}
	

	exit(EXIT_SUCCESS);
}