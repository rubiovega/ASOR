/* Escribir un programa que muestre el contenido de un directorio:
-El programa tiene un único argumento que es la ruta a un directorio. 
El programa debe comprobar la corrección del argumento.
-El programa recorrerá las entradas del directorio y escribirá su nombre de fichero. Además:
    Si es un fichero regular y tiene permiso de ejecución para usuario, grupo u otros, escribirá el carácter ‘*’ después del nombre.
    Si es un directorio, escribirá el carácter ‘/’ después del nombre
    Si es un enlace simbólico, escribirá “->” y el nombre del fichero enlazado después del nombre. Usar readlink(2).
-Al final de la lista, el programa escribirá el tamaño total que ocupan los ficheros (no directorios) en kilobytes.*/

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <errno.h>
using namespace std;

int main(int argc, char **argv)
{
    if (argc < 2) 
    {
     cout << "usage: ./ejer17 <dir>" << endl;
     return -1;
    }

    struct stat buf;

    int rc = lstat(argv[1], &buf);     
    if (rc == -1)
    {
        cout << "[lstat]: " << strerror(errno) << endl;
        return -1;
    }

    if (!S_ISDIR(buf.st_mode))
    {
        cout << "[error]: El argumento no es un directorio" << endl;
        return -1;
    }

    else
    {
    DIR *d = opendir(argv[1]);
    struct dirent *next;
    next = readdir(d);
    int l=0;

    while (next!=NULL)
    {
        cout << next->d_name << " ";
        switch (next->d_type)
        {
            case DT_DIR:
                cout << "/" << endl;
                break;
            
            case DT_REG:
                cout << "*" << endl;
                l+=next->d_off;
                break;

            case DT_LNK:
                char buf[200];
                string path = "./";
                path += next->d_name;
                readlink(path.c_str(),buf,sizeof(buf));
                cout << "-> " << buf << endl;
                break;

        }
        next = readdir(d);
    }

    closedir(d);

    cout << "Tamaño total ficheros: " << l  << " KB"<< endl;

    return 0;
    }
    


}