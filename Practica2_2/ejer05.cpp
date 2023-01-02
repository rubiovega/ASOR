/*Escribir un programa que, usando open(2), cree un fichero con los permisos rw-r--r-x. */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <iostream>
using namespace std;

int main(){
    int fd = open ("./fichero",O_CREAT,0645);
    if (fd == -1)
    {
        cout << "[open]: " << strerror(errno) << endl;
        return -1;
    }

    return 0;
}