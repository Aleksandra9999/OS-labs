#include<stdio.h> 

#include<stdlib.h> 

#include<unistd.h> 

#include<sys/types.h> 
 
 

int main() 
{

  
  int se[2];

    char str[] = "Risotto";

    pid_t p;

    
  
    pipe(se);


    
p = fork();


    
    
    //parent

    if (p > 0) {
 
       close(se[0]);

	write(se[1], str, strlen(str)+1);
 
       close(se[1]);
 
    }
 
  
  
     // child process
 
    else if (p == 0)
 {
	close(se[1]);

	char copy_str[100];
 
       read(se[0], copy_str, 100);
 
       
 
       close(se[0]);

        

        puts(copy_str);

  
      
	exit(0);
	}
}
