#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tp(){
    printf("[computer]$ ");
}

int main()
{
 char command[100];
 char *line[100];
 int number;
 tp();
 gets(command);  
    char *token = strtok(command, " "); 
    while (token != NULL) 
    {
        line[number] = token;

        number = number + 1;
        token = strtok(NULL, " "); 
    }

    execvp(line[0], line);

    return 0;
}