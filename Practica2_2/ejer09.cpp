/*Escribir un programa que emule el comportamiento del comando stat y muestre:
El número major y minor asociado al dispositivo.
El número de i-nodo del fichero.
El tipo de fichero (directorio, enlace simbólico o fichero ordinario).
La hora en la que se accedió el fichero por última vez.*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include <errno.h>
using namespace std;

int main(int argc, char **argv){
    
    if (argc < 2) 
    {
     cout << "usage: ./ejer09 <file>" << endl;
     return -1;
    }
    
    struct stat buf;

    int rc = lstat(argv[1], &buf);
    
    if (rc == -1)
    {
        cout << "[lstat]: " << strerror(errno) << endl;
        return -11;
    }


    else 
    {
        cout << "Major Number: " << major(buf.st_dev) << endl;
        cout << "Minor Number: " << minor(buf.st_dev) << endl;    
        cout << "I-Node Number: " << buf.st_ino << endl;
        if (S_ISLNK(buf.st_mode))
            cout << "Symbolic link" << endl;

        else if (S_ISDIR(buf.st_mode))
            cout << "Directory" << endl;

        else if (S_ISREG(buf.st_mode))
            cout << "Regular File" << endl;

        struct tm *tm= localtime(&buf.st_atime);
        char legible[200];
        strftime(legible,sizeof(legible),"%c",tm);

        cout << "Last access: " << legible << endl;
        

    }

    

    return 0;

}