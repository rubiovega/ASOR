#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <errno.h>
#include <string.h>
using namespace std;

const int SIZE=512;

int main (int argc, char **argv)
{
    int p_h[2], h_p[2], bytes;
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
            close(p_h[1]);
            close(h_p[0]);

            for (size_t i = 0; i < 10; i++) 
            {
                bytes = read(p_h[0], buffer, sizeof(buffer));
                write(0, "[HIJO] Mensaje: ", 17);
                write(0, buffer, bytes);

                sleep(1);
                if(i == 9) flag = 'q';
                write(h_p[1], &flag, 1);
            }

            close(p_h[0]);
            close(h_p[1]);
            break;

        default: //PADRE
            flag = 'l';

            close(p_h[0]);
            close(h_p[1]);

            while(flag != 'q'){
                write(0, "[PADRE] Mensaje: ", 18);
                bytes = read(0, buffer, sizeof(buffer));
                write(p_h[1], buffer, bytes);
                read(h_p[0], &flag, 1);
            }

            cout << "10 mensajes enviados con éxito. Saliendo..." << endl;

            close(p_h[1]);
            close(h_p[0]);

            break;
    }
}