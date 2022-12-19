#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <algorithm>  
using namespace std;

int main()
{
    fd_set fdset;
    char buffer[256];
    int bytes;
    int fd1 = open("./tub1", O_RDWR | O_NONBLOCK);
    int fd2 = open("./tub2", O_RDWR | O_NONBLOCK);

    FD_ZERO(&fdset);
    FD_SET(fd1, &fdset);
    FD_SET(fd2, &fdset);
    
    select(max(fd1,fd2)+1,&fdset,NULL,NULL,NULL);
    
    if (FD_ISSET(fd1, &fdset))
    {
        bytes = read(fd1,buffer,255);
        write(0, "[Leido de TUB1]: ", 17);
        write(0, buffer, bytes);
        close(fd1);
    }

    else if (FD_ISSET(fd2, &fdset))
    {
        bytes = read(fd2,buffer,255);
        write(0, "[Leido de TUB2]: ", 17);
        write(0, buffer, bytes);
        close(fd2);
    }

    return 0;
}