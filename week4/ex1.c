#include <stdio.h>

#include <stdlib.h>


int main(void) {

int n = fork();

if (n > 0)
    
    printf("Hello from parent [PID - %d]\n", n);

else if (n == 0)
    
    printf("Hello from child [PID - %d]\n", n);
    
    

    return 0;

}
