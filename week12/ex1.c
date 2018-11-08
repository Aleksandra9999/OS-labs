#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int file = open("/dev/random", O_RDONLY);
    
    char str[21];
    str[20] = '\0'; // Add null terminator
    read(file, str, 20);
    printf("%s\n", str);
    
    close(file);
    
    return 0;
}