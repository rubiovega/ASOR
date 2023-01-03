/*Escribir dos versiones, una con system(3) y otra con execvp(3), 
de un programa que ejecute otro programa que se pasará como argumento por 
línea de comandos. En cada caso, se debe imprimir la cadena 
“El comando terminó de ejecutarse” después de la ejecución*/

#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char **argv)
{
    system(argv[1]);
    execvp(argv[1],argv[1]);

    return 0;
}

