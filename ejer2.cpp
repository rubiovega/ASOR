#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <iostream>
using namespace std;

char *strerror(int errnum);
int setuid(uid_t uid);
void perror(const char *s);
int errno;

      
   int main() {
        int rc;
        rc = setuid(0);
      
        if (rc == -1){
            cout << errno << " " << strerror(errno) << endl;
            return -1;

        }

        return 0;
    }
