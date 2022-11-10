#include <iostream>
using namespace std;
#include <sys/time.h>
const long int MAX_IT=1000000;

int main(){
    struct timeval ini;
    struct timeval fin;
    struct timezone tz;

    gettimeofday(&ini, &tz);

    for (int i=0;i<MAX_IT;i++);

    gettimeofday(&fin, &tz);
    cout << fin.tv_usec - ini.tv_usec << endl;

    return 0;
}