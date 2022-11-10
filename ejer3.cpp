#include <iostream>
using namespace std;
#include <string.h>

char *strerror(int errnum);
const int MAX_ERRORS = 255;

int main(){
    for (int i=0;i<MAX_ERRORS;i++){
        cout << strerror(i) << endl;
    }
}