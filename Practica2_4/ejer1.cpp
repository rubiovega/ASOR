/*Escribir un programa que emule el comportamiento de la shell en la ejecución 
de una sentencia en la forma: comando1 argumento1 | comando2 argumento2. 
El programa creará una tubería sin nombre y creará un hijo:
El proceso padre redireccionará la salida estándar al extremo de escritura 
de la tubería y ejecutará comando1 argumento1.
El proceso hijo redireccionará la entrada estándar al extremo de lectura 
de la tubería y ejecutará comando2 argumento2.*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <errno.h>
#include <string.h>
using namespace std;

int main (int argc, char **argv)
{
    if (argc != 5)
    {
        cout << "Usage: ./ejer1 <com1> <arg1> <com2> <arg2>" << endl;
        return -1;
    }

    int fd[2];
    int rc = pipe(fd);

     if (rc == -1)
    {
        cout << "[pipe]: " << strerror(errno) << endl;
        exit(EXIT_FAILURE);
    }   

    pid_t pid = fork();
   
    switch(pid)
    {
        case -1: //ERROR
            cout << "[fork]: " << strerror(errno) << endl;
            exit(EXIT_FAILURE);
            break;

        case 0: //HIJO
        {
            dup2(fd[0],0);
            close(fd[1]);
            int rc_h = execlp(argv[3], argv[3], argv[4], (char *) 0);
            if (rc_h == -1)
            {
                cout << "[execv] HIJO: " << strerror(errno) << endl;
            }
            break;
        }

        default: //PADRE
        {
            dup2(fd[1],1);
            close(fd[0]);
            int rc_p = execlp(argv[1], argv[1],argv[2],(char *) 0);
            if (rc_p == -1)
            {
                cout << "[execv] PADRE: " << strerror(errno) << endl;
            }
            break;
            
        }
    }

    return 0;
}