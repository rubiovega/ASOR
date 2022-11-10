#include <iostream>
using namespace std;
#include <time.h>


int main(){
    struct tm *result;
    time_t *t;

    result=localtime(t);
    cout << result->tm_year << endl;

    return 0;
}