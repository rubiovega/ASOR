#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <errno.h>
#include <string.h>
using namespace std;

const int SIZE=512;

int main (int argc, char **argv)
{
    int p_h[2], h_p[2], readbytes;
    char flag,buffer[SIZE];
    pipe(p_h);
    pipe(h_p);

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

            for (size_t i = 0; i < 10; i++) 
            {
                read(p_h[0], buffer, 1);
                printf("[HIJO] Recibido: ", buffer);
                sleep(1);
                if(i == 9) flag = 'q';
                write(h_p[1], &flag, 1);
            }
            break;

        default: //PADRE
            cout << "Padre " << getpid()<< " - " << getppid() << endl;
            flag = 'l';

            close(p_h[0]);
            close(h_p[1]);

            while(flag != 'q'){
                cout << "[PADRE] Mensaje:";
                read(0, buffer, 255);
                write(p_h[1], buffer, 255);
                read(h_p[0], &flag, 1);
            }

            printf("10 mensajes enviados con éxito. Saliendo...\n");
            break;
    }
}