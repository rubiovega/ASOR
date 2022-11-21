/*Escribir un programa que obtenga, con sysconf(3), información de configuración del 
sistema e imprima, por ejemplo, la longitud máxima de los argumentos, el número máximo de hijos 
y el número máximo de ficheros.*/


#include <iostream>
#include <unistd.h>
using namespace std;

int main(){
    cout << "Max arguments: " << sysconf(_SC_ARG_MAX)<< endl;
    cout << "Max child: " << sysconf(_SC_CHILD_MAX)<< endl;
    cout << "Max file: " << sysconf(_SC_OPEN_MAX)<< endl;

    return 0;
}