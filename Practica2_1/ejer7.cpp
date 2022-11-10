#include <iostream>
#include <unistd.h>
using namespace std;

int main(){
    cout << pathconf("./", _PC_LINK_MAX) << endl;
    cout << pathconf("./", _PC_NAME_MAX) << endl;
    cout << pathconf("./", _PC_PATH_MAX) << endl;


    return 0;
}