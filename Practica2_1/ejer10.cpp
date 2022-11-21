/*Modificar el programa anterior para que muestre además el nombre de usuario, 
el directorio home y la descripción del usuario.*/

#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <iostream>
using namespace std;

int main()
{
    uid_t uid = getuid();
    cout << "UID: " << uid << endl;
    cout << "EUID: " << geteuid() << endl;

    struct passwd *pw = getpwuid (uid);

    cout << "Username: " << pw->pw_name << endl;
    cout << "home: " << pw->pw_dir << endl;
    cout << "User description: " << pw->pw_gecos << endl;

    return 0;
}