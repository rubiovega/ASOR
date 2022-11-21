/*Escribir un programa que mida, en microsegundos, 
lo que tarda un bucle que incrementa una variable un millón 
de veces usando gettimeofday(2).*/

#include <iostream>
using namespace std;
#include <sys/time.h>
const long int MAX_IT=1000000;

int main(){
    struct timeval ini;
    struct timeval fin;

    gettimeofday(&ini, NULL);

    for (int i=0;i<MAX_IT;i++);

    gettimeofday(&fin, NULL);
    cout << "Miliseconds: " << fin.tv_usec - ini.tv_usec << endl;

    return 0;
}