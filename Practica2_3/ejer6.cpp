/*Escribir una plantilla de demonio (creación del nuevo proceso y de la sesión) en el que
 únicamente se muestren los atributos del proceso (como en el ejercicio anterior). 
 Además, fijar el directorio de trabajo del demonio a /tmp.*/

#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <string.h>
using namespace std;

int main()
{
    pid_t pid= fork();
    char ncwd[200];

    switch(pid)
    {
        case -1:
            cout << "[fork]: " << strerror(errno) << endl;
            _exit(-1);
        break;

        case 0:
        {
            pid_t mi_sid = setsid();
            chdir("/tmp");
            getcwd(ncwd, sizeof(ncwd));
            cout << ncwd << endl;

            cout << "PID: " << getpid() << endl;
            cout << "PPID: " << getppid() << endl;
            cout << "PGID: " << getpgid(pid) << endl;
            cout << "SID: " << getsid(pid) << endl;         
        }
        break;

        default:
            sleep(100);
        break;
    }
}