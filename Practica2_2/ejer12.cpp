/*Escribir un programa que redirija la salida estándar a un fichero 
cuya ruta se pasa como primer argumento. Probar haciendo que el programa escriba 
varias cadenas en la salida estándar.*/

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
    write (1, "Salida standar redirigida a fichero\n", sizeof(char)*36);

    return 0;
}