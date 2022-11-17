#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

//TODO

int main()
{
    int fd = open ("./fichero",O_CREAT,0777);
    cout << fd << endl;
    int rc = lockf(fd,F_TLOCK,2);

    if (rc == -1)
    {
        cout << strerror(errno) << endl;
    }
    else 
    {
        char outstr[200];
        struct tm *result;
        time_t t = time(NULL);

        result=localtime(&t);
        strftime(outstr,sizeof(outstr),"%c",result);

        sleep(10);
    }
}