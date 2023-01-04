/*Escribir un programa que abra la tubería con el nombre anterior 
en modo sólo escritura, y escriba en ella el primer argumento del programa. 
En otro terminal, leer de la tubería usando un comando adecuado.*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib>
#include <erno.h>
#include <string.h>
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int rc = mkfifo("./pipe2c",0777);
    if (rc == -1)
    {
        cout << "[mkfifo]: " << strerror(errno) << endl;
        exit(EXIT_FAILURE);

    }

    int fd = open("./pipe2c", O_WRONLY);

    if (fd == -1)
    {
        cout << "[open]: " << strerror(errno) << endl;
        exit(EXIT_FAILURE);
    }

    write(fd,argv[1], sizeof(argv[1]));
    close (fd);
   

    return 0;
}
