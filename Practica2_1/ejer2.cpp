/*Imprimir el código de error generado por la llamada del código anterior, 
tanto en su versión numérica como la cadena asociada.*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <iostream>
using namespace std;

int errno;

      
   int main() {
        int rc;
        rc = setuid(0);
      
        if (rc == -1){
            cout << errno << " " << strerror(errno) << endl;
            return 1;

        }

        return 0;
    }
