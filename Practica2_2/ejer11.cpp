/*Escribir un programa que reciba una ruta a un fichero como argumento. 
Si la ruta es un fichero regular, creará un enlace simbólico y rígido 
con el mismo nombre terminado en .sym y .hard, respectivamente. Comprobar el resultado con ls(1).*/

#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <iostream>
using namespace std;

int main(int argc, char **argv){
    struct stat buf;

    int rc = lstat(argv[1], &buf);
    
   if (rc == -1)
    {
        cout << "[lstat]: " << strerror(errno) << endl;
        return -1;
    }
    
    else if (S_ISREG(buf.st_mode))
    {
        cout << "Regular File" << endl;
        string hard = argv[1];
	    string sym = argv[1];
	    hard += ".hard";
	    sym += ".sym";

        const char *h = hard.c_str();
        const char *s = sym.c_str();

        link(argv[1],h);
        symlink(argv[1],s);
    }
}