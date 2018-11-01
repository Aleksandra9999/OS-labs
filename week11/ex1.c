#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    char *str = "This is a nice day";
    int newfile = open("ex1.txt", O_RDWR);

    int size = strlen(str);

    char *file = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, newfile, 0);
    ftruncate(newfile, size);

    for (int i = 0; i < size; i++)
        file[i] = str[i];

    munmap(file, size);

    return 0;
}