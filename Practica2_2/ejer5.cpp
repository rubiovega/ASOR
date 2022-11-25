/*Escribir un programa que, usando open(2), cree un fichero con los permisos rw-r--r-x. */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    open ("./fichero",O_CREAT,0645);

    return 0;
}