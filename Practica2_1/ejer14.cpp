#include <iostream>
using namespace std;
#include <time.h>


int main(){
    struct tm *result;
    time_t t = time(NULL);

    result=localtime(&t);
    int year = result->tm_year + 1900;

    cout << year << endl;

    return 0;
}