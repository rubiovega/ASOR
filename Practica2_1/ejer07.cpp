/*Escribir un programa que obtenga, con pathconf(3), información de configuración 
del sistema de ficheros e imprima, por ejemplo,  el número máximo de enlaces, el 
tamaño máximo de una ruta y el de un nombre de fichero.*/

#include <iostream>
#include <unistd.h>
using namespace std;

int main(){
    cout << "Max link: " << pathconf("./", _PC_LINK_MAX) << endl;
    cout << "Max path size: " << pathconf("./", _PC_PATH_MAX) << endl;
    cout << "Max file name: " << pathconf("./", _PC_NAME_MAX) << endl;


    return 0;
}