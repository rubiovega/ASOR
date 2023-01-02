/* Escribir un programa que muestre el año usando localtime(3).*/

#include <iostream>
using namespace std;
#include <time.h>


int main(){
    struct tm *result;
    time_t t = time(&t);

    result=localtime(&t);
    int year = result->tm_year + 1900;

    cout << "Year: " << year << endl;

    return 0;
}