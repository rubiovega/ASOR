#include <time.h>
#include <iostream>
using namespace std;

int main(){
    time_t t;

    cout << time(&t) << endl;

    return 0;
}