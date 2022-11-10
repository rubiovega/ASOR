#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
void perror(const char *s);

#include <errno.h>

      
   int main() {
        int rc;
        rc = setuid(0);
      
        if (rc == -1)
                return -1;

        return 0;
    }
