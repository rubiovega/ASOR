/*Añadir el código necesario para gestionar correctamente los 
errores generados por la llamada a setuid(2)*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

      
   int main() {
        int rc;
        rc = setuid(0);
      
        if (rc == -1)
                return 1;

        else return 0;
    }
