/*Escribir un programa que instale un manejador para las señales SIGINT y SIGTSTP. 
El manejador debe contar las veces que ha recibido cada señal. 
El programa principal permanecerá en un bucle que se detendrá 
cuando se hayan recibido 10 señales. El número de señales de cada tipo
se mostrará al finalizar el programa. */

#include <iostream>
#include <signal.h>
#include <unistd.h>
using namespace std;

volatile static int contador_int = 0;
volatile static int contador_tstp = 0;

void handler(int signal)
{
    if (signal == SIGINT) contador_int++;
    if (signal == SIGTSTP) contador_tstp++;
}

int main()
{
    
    struct sigaction act;

    sigaction(SIGINT,NULL,&act);
    act.sa_handler=handler;
    sigaction(SIGINT,&act,NULL);

    sigaction(SIGTSTP,NULL,&act);
    act.sa_handler=handler;
    sigaction(SIGTSTP,&act,NULL);

    sigset_t set;
    sigemptyset(&set);

    while(contador_int + contador_tstp < 10)
    {
        sigsuspend(&set);
    }

    cout << "SIGINT capturadas " << contador_int << endl;
    cout << "SIGTSTP capturadas " << contador_tstp << endl;

    return 0;
}