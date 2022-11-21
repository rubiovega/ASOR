/*Escribir un programa que muestre, con uname(2), cada aspecto del sistema y su valor. 
Comprobar la correcta ejecución de la llamada.*/

#include <iostream>
using namespace std;
#include <sys/utsname.h>

int main(){
    int rc;
    struct utsname buf;

    rc = uname(&buf);

    if (rc == -1){
        return 1;
    }
        

    cout << "System Name: " << buf.sysname << endl;
    cout << "Node name: " << buf.nodename << endl;
    cout << "Release: " << buf.release << endl;
    cout << "Version: " << buf.version << endl;
    cout << "Machine: " << buf.machine << endl;


    return 0;

}