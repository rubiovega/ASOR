#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    int fd = open(argv[1],O_RDWR);
    dup2(fd,1);
    dup2(fd,2);
    write (1, "Salida standar redirigida a fichero\n", sizeof(char)*36);
    write (2, "Salida standar de error redirigida a fichero\n", sizeof(char)*45);

    return 0;
}