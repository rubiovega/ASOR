#include <iostream>
using namespace std;
#include <time.h>


int main(){
    char outstr[200];
    struct tm *result;
    time_t t = time(NULL);

    result=localtime(&t);
    strftime(outstr,sizeof(outstr),"%c",result);

    cout << outstr << endl;

    return 0;
}