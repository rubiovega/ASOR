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
    //el ejercicio cuenta con que tub1 y tub2 existen, por lo que deben crearse con $mkfifo <tuberia>
    int fd1 = open("./tub1", O_RDWR | O_NONBLOCK);
    if (fd1 == -1)
    {
        cout << "[open]: " << strerror(errno) << endl;
        exit(EXIT_FAILURE);
    }

    int fd2 = open("./tub2", O_RDWR | O_NONBLOCK);
    if (fd2 == -1)
    {
        cout << "[open]: " << strerror(errno) << endl;
        exit(EXIT_FAILURE);
    }
    
    FD_ZERO(&fdset);
    FD_SET(fd1, &fdset);
    FD_SET(fd2, &fdset);
    
    int rc = select(max(fd1,fd2)+1,&fdset,NULL,NULL,NULL);
    if (rc == -1)
    {
        cout << "[select]: " << strerror(errno) << endl;
        exit(EXIT_FAILURE);
    }
    
    if (FD_ISSET(fd1, &fdset))
    {
        bytes = read(fd1,buffer,sizeof(buffer));
        write(0, "[Leido de TUB1]: ", 17);
        write(0, buffer, bytes);
        close(fd1);
    }

    else if (FD_ISSET(fd2, &fdset))
    {
        bytes = read(fd2,buffer,sizeof(buffer));
        write(0, "[Leido de TUB2]: ", 17);
        write(0, buffer, bytes);
        close(fd2);
    }

    return 0;
}