 /*Modificar el ejercicio 5 para que, antes de crear el fichero, se fije la máscara 
con umask de forma que los nuevos ficheros no tengan permiso de escritura para el 
grupo y no tengan ningún permiso para otros*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    umask(0027);
    open ("./fichero",O_CREAT,0645);

    return 0;
}