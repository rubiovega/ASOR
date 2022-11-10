#include <iostream>
using namespace std;
#include <sys/time.h>
const long int MAX_IT=1000000;

int main(){
    struct timeval tv;
    struct timezone tz;

    for (int i=0;i<MAX_IT;i++);

    gettimeofday(&tv, &tz);
    cout << tv.tv_usec << endl;

    return 0;
}