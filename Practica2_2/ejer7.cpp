#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    umask(0037);
    open ("./fichero",O_CREAT,0645);

    return 0;
}