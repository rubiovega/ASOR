
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <iostream>
#include <unistd.h>
using namespace std;

int main(int argc, char **argv)
{
    struct stat buf;

    lstat(argv[1], &buf);
    if (!S_ISDIR(buf.st_mode))
    {
        cout << "El argumento no es un directorio" << endl;
        return -1;
    }
    else
    {
    DIR *d = opendir(argv[1]);
    struct dirent *next;
    next = readdir(d);
    int l=0;

    while (next!=NULL)
    {
        cout << next->d_name << " ";
        switch (next->d_type)
        {
            case DT_DIR:
                cout << "/" << endl;
                break;
            
            case DT_REG:
                cout << "*" << endl;
                l+=next->d_off;
                break;

            case DT_LNK:
                char buf[200];
                string path = "./";
                path += next->d_name;
                readlink(path.c_str(),buf,sizeof(buf));
                cout << "-> " << buf << endl;
                break;

        }
        next = readdir(d);
    }

    closedir(d);

    return 0;
    }
    


}