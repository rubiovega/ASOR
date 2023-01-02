/*Modificar el programa anterior para que imprima la hora de forma legible, 
como "lunes, 29 de octubre de 2018, 10:34", usando la función strftime(3).*/

#include <iostream>
using namespace std;
#include <time.h>


int main(){
    char legible[200];
    struct tm *result;
    time_t t = time(&t);

    result=localtime(&t);
    strftime(legible,sizeof(legible),"%c",result);

    cout << "Date: " << legible << endl;

    return 0;
}