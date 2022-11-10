#include <iostream>
using namespace std;
#include <sys/utsname.h>

int main(){
    int rc;
    struct utsname buf;

    rc = uname(&buf);

    if (rc == -1){
        return -1;
    }
        

    cout << buf.sysname << endl;
    cout << buf.nodename << endl;
    cout << buf.release << endl;
    cout << buf.version << endl;
    cout << buf.machine << endl;


    return 0;

}