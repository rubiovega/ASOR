#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    open ("./fichero",O_CREAT,0645);

    return 0;
}