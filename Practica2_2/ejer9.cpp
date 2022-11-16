#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, char **argv){
    //error en la llamada stat
    struct stat *buf;
    int errnum;

    int rc = stat(argv[1], buf);
    
    if (rc == 0){
        cout << buf->st_mode << endl;
    }
    else cout << strerror(errnum) << endl;
    return 0;

}