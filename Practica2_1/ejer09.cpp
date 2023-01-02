/*Escribir un programa que muestre, igual que id, el UID real y efectivo del usuario.*/

#include <unistd.h>
#include <sys/types.h>
#include <iostream>
using namespace std;

int main()
{
    cout << "UID: " << getuid() << endl;
    cout << "EUID: " << geteuid() << endl;

    return 0;
}