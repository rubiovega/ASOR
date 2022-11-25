/*Escribir un programa que muestre la política de planificación (como cadena) 
y la prioridad del proceso actual, además de mostrar los valores máximo y 
mínimo de la prioridad para la política de planificación. */

#include <sched.h>
#include <iostream>
using namespace std;

int main()
{
    int pol = sched_getscheduler(0);
    cout << "Policy: ";

    switch(pol)
    {
        case 0:
        cout << "SCHED_OTHER" << endl;
        break;

        case 1:
        cout << "SCHED_FIFO" << endl;
        break;

        case 2:
        cout << "SCHED_RR" << endl;
        break;

        case 3:
        cout << "SCHED_BATCH" << endl;
        break;

        case 5:
        cout << "SCHED_IDLE" << endl;
        break;
    }

    struct sched_param p;

    sched_getparam(0,&p);

    cout << "Priority: " << p.__sched_priority << endl;

    cout << "Max Priority: " << sched_get_priority_max(pol) << endl;
    cout << "Min Priority: " << sched_get_priority_min(pol) << endl;

}