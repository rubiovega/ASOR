#include <iostream>
#include <unistd.h>
using namespace std;

int main(){
    cout << sysconf(_SC_ARG_MAX)<< endl;
    cout << sysconf(_SC_CHILD_MAX)<< endl;
    cout << sysconf(_SC_OPEN_MAX)<< endl;

    return 0;
}