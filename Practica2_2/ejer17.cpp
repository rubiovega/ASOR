#include <sys/types.h>
#include <dirent.h>
#include <iostream>
#include <unistd.h>
using namespace std;

int main(int argc, char **argv)
{
    DIR *d = opendir(argv[1]);
    if (d == NULL)
    {
        return -1;
    }

    struct dirent *next;
    next = readdir(d);
    while (next != NULL)
    {
        cout << next->d_name << " ";
        switch (next->d_type)
        {
            case DT_DIR:
                cout << "/" << endl;
                break;
            
            case DT_REG:
                cout << "*" << endl;
                //sumar tamaños
                break;

            case DT_LNK:
                cout << "->" << endl;
                break;

        }
        next = readdir(d);
    }

    closedir(d);

    return 0;

}