/*
Escribir un programa que realice el borrado programado del propio ejecutable. 
El programa tendrá como argumento el número de segundos que esperará antes de borrar el fichero. 
Para notificar el final de la espera el programa instalará una alarma con la llamada 
al sistema alarm(2). El borrado del fichero se podrá detener si se recibe la señal 
SIGUSR1 antes de que termine el periodo de espera
*/

#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

void handler (int signal)
{
    cout << "SIGALRM recibida" << endl;
}

int main(int argc, char **argv)
{
    if (argc != 2) 
    {
        cout << "usage: ./ejer13 <s>";
        return -1;
    }

    int secs = atoi(argv[1]);
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set,SIGUSR1);
    sigprocmask(SIG_UNBLOCK, &set, NULL);
    signal(SIGALRM, handler);
    alarm(secs);
    sigsuspend(&set);
    unlink(argv[0]);

    return 0;
}