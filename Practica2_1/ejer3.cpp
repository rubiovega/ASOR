/*Escribir un programa que imprima todos los mensajes de error disponibles en el sistema. 
Considerar inicialmente que el límite de errores posibles es 255.*/

#include <iostream>
using namespace std;
#include <string.h>

const int MAX_ERRORS = 255;

int main(){
    
    for (int i=0;i<MAX_ERRORS;i++)
    {
        cout << "Error Number " + i << endl;
        cout << strerror(i) << endl;
    }
    return 0;
        
}