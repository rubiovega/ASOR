/*Escribir un programa que muestre la hora, en segundos desde el Epoch, usando time(2). */

#include <time.h>
#include <iostream>
using namespace std;

int main(){
    time_t t = time(NULL);

    cout << "Time as the number of seconds since the Epoch: " << time(&t) << endl;

    return 0;
}