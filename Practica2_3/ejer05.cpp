/*Escribir un programa que muestre los identificadores del proceso (PID, PPID, PGID y SID),
 el número máximo de ficheros que puede abrir y su directorio de trabajo actual.*/

#include <unistd.h>
#include <iostream>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
using namespace std;

int main()
{
    pid_t pid;

    pid = fork();

    switch(pid)
    {
        case 0:
        cout << "Hijo. PID: " << getpid() << " " << getppid() << " " << getpgid(pid) << " " << getsid(pid) << endl; 
        break;

        default:
        cout << "Padre. PID: " << getpid() << " " << getppid() << " " << getpgid(pid) << " " << getsid(pid) << endl; 
        break;

    }

    char dir[200];
    cout << "Directorio Trabajo: " << getcwd(dir, sizeof(dir)) << endl;

    struct rlimit rlim;
    getrlimit(RLIMIT_NOFILE,&rlim);

    cout << "Max ficheros abiertos: " << rlim.rlim_max << endl;

    return 0;
}