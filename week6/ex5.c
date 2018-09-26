#include<stdio.h>

#include<signal.h>

#include<stdlib.h>

#include<unistd.h>
#include<sys/types.h> 

int main() 
{



    pid_t p;


    p = fork();

    
if (p>0) {

       sleep(10);

       kill(p, SIGTERM);

    }

    

    else if (p==0) {

        while(1){

            printf("I'm alive\n");

            sleep(1);

        }

 
    }


return 0;

}
