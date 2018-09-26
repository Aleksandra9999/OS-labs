#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


void handle_signal(int sig) {
   printf("Signal %d\n", sig);
   exit(1);
}



int main (void) {
    
    signal(SIGINT, handle_signal);
    while (1)
        sleep (10);
    return 0;
}