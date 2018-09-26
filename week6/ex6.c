#include<stdio.h>

#include<signal.h>

#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>


int main() 
{


    pid_t p1;

    pid_t p2;

    int fd1[2];

    

    pipe(fd1);


    p1 = fork();

    

    

    if (p1 > 0) {


        int fd2[2];

        pipe(fd2);

    
    
    	p2 = fork();

        

        
if (p2==0){

		close(fd2[0]);

        	int pid2 = getpid();

	        write(fd2[1], &pid2, sizeof(pid2));

        	close(fd2[1]);

            
    
    	}


        else if (p2>0){

        
    
            close(fd2[1]);

	        int pid;

        	read(fd2[0], &pid, sizeof(pid));

        	close(fd2[0]);

            
    
		close(fd1[0]);

		write(fd1[1], &pid, sizeof(pid));

        	close(fd1[1]);


		int *status;

		waitpid(pid, status, 0);


        }

 
    }


 
    else if (p1 == 0){


	close(fd1[1]);


	int pid;

 
       read(fd1[0], &pid, sizeof(pid));

        close(fd1[0]);

        

        sleep(30);

        kill(pid, SIGSTOP);

        

	exit(0);


	}

    
return 0;

}