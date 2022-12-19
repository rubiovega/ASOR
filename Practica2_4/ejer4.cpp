/*Escribir un programa que abra la tubería con el nombre anterior 
en modo sólo escritura, y escriba en ella el primer argumento del programa. 
En otro terminal, leer de la tubería usando un comando adecuado.*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    mkfifo("./pipe2c",0777);
    int fd = open("./pipe2c", O_WRONLY);

    if (fd!=-1)
    {
        write(fd,argv[1], sizeof(argv[1]));
        close (fd);
    }
   

    return 0;
}
