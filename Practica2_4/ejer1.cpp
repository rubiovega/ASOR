/*Escribir un programa que emule el comportamiento de la shell en la ejecución 
de una sentencia en la forma: comando1 argumento1 | comando2 argumento2. 
El programa creará una tubería sin nombre y creará un hijo:
El proceso padre redireccionará la salida estándar al extremo de escritura 
de la tubería y ejecutará comando1 argumento1.
El proceso hijo redireccionará la entrada estándar al extremo de lectura 
de la tubería y ejecutará comando2 argumento2.*/

#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <errno.h>
#include <string.h>
using namespace std;

int main (int argc, char **argv)
{
    int fd[2];
    pipe(fd);

    pid_t pid;
    pid = fork();
   
    switch(pid)
    {
        case -1: //ERROR
            perror("fork()");
            return 1;
            break;

        case 0: //HIJO
            cout << "Hijo " << getpid()<< " - " << getppid() << endl;
            dup2(fd[0],0);
            close(fd[1]);
            execlp(argv[3], argv[3], argv[4], (char *) 0);
            cout << strerror(errno) << endl;
            cout << "NO SE EJECUTA SI EXEC HIJO FUNCIONA"  << endl;
            break;

        default: //PADRE
            cout << "Padre " << getpid()<< " - " << getppid() << endl;
            dup2(fd[1],1);
            close(fd[0]);
            execlp(argv[1], argv[1],argv[2],(char *) 0);
            cout << "NO SE EJECUTA SI EXEC PADRE FUNCIONA"  << endl;
            break;
    }
}