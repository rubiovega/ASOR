#include <unistd.h>

int main(int argc, char **argv){
    link(argv[1],".hard");
    symlink(argv[1],".sym");
}