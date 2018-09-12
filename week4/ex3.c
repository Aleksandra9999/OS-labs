#include <stdio.h>
#include <stdlib.h>

void tp(){
    printf("[computer]$ ");
}

void read(char *command){
    scanf("%s", command);
}


int main(void) {
    char command[10];
    while (1) {
    tp();
    read(command);
    system(command);
    }
return 0;
}