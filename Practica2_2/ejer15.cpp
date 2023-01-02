/*Escribir un programa que intente bloquear un fichero usando lockf(3):
Si lo consigue, mostrará la hora actual y suspenderá su ejecución durante 10 segundos con sleep(3). 
A continuación, desbloqueará el fichero, suspenderá su ejecución durante otros 10 segundos y terminará.
Si no lo consigue, el programa mostrará el error con perror(3) y terminará.*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <string.h>
using namespace std;

int main(int argc, char **argv)
{
    if (argc < 2) 
    {
     cout << "usage: ./ejer15 <file>" << endl;
     return -1;
    }

    int fd = open ("./fichero",O_CREAT | O_RDWR,0777);
    if (fd == -1)
    {
        cout << "[open]: " << strerror(errno) << endl;
        return -1;
    }

    int rc = lockf(fd,F_LOCK,0);

    if (rc == -1)
    {
       cout << "[lockf]: " << strerror(errno) << endl;
       return -1;
    }

    else 
    {
        cout << "Cerrojo Bloqueado" << endl;

        char legible[200];
        struct tm *result;
        time_t t = time(&t);

        result=localtime(&t);
        strftime(legible,sizeof(legible),"%c",result);

        cout << "Date: " << legible << endl;

        sleep(10);
        lockf(fd,F_ULOCK,0);
        
        cout << "Cerrojo Desbloqueado" << endl;

        sleep(10);

    }

    return 0;

}