/*Escribir un programa que bloquee las señales SIGINT y SIGTSTP. 
Después de bloquearlas el programa debe suspender su ejecución con sleep(3) 
un número de segundos que se obtendrán de la variable de entorno SLEEP_SECS. 
Al despertar, el proceso debe informar de si recibió la señal SIGINT y/o SIGTSTP. 
En este último caso, debe desbloquearla con lo que el proceso se detendrá 
y podrá ser reanudado en la shell (imprimir una cadena antes de finalizar el 
programa para comprobar este comportamiento).*/

#include <iostream>
#include <signal.h>
#include <unistd.h>
using namespace std;

int main()
{
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    sigaddset(&set, SIGTSTP);

    sigprocmask(SIG_BLOCK, &set,0);

    sleep(40);

    sigpending(&set);

    if (sigismember(&set,SIGINT))
    {
        cout << "Recibida SIGINT" << endl;
    }

    if (sigismember(&set,SIGTSTP))
    {
        cout << "Recibida SIGSTP" << endl;
        sigprocmask(SIG_UNBLOCK, &set,0);
    }

    cout << "El Programa terminó su ejecucion" << endl;

    return 0;
}