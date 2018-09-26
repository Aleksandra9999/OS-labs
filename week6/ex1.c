#include<stdio.h>

#include<stdlib.h>

#include<unistd.h>

#include<sys/types.h>

int main() 
{

	int se[2];
	char str[] = "Risotto";

	char copy_str[100];


    
    pipe(se);


    
    write(se[1], str, strlen(str)+1);


	close(se[1]);


    
    read(se[0], copy_str, 100);

	close(se[0]);


        
puts(copy_str);


}