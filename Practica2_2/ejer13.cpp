/*Modificar el programa anterior para que también redirija la salida estándar de error al fichero. 
/*Comprobar el funcionamiento incluyendo varias sentencias que impriman en ambos flujos. */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int fd = open(argv[1],O_RDWR);
    if (fd == -1)
    {
        cout << "[open]: " << strerror(errno) << endl;
        return -1;
    }

    dup2(fd,1);
    dup2(fd,2);
    write (1, "Salida standar redirigida a fichero\n", sizeof(char)*36);
    write (2, "Salida standar de error redirigida a fichero\n", sizeof(char)*45);

    return 0;
}