#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int thread_id[15];

void * print(int i) {
    printf("Created new thread: %d in iteration %d\n", (int) pthread_self(), i);
    sleep(2);
    pthread_exit(NULL);
}

int main(int argc, char * argv[]) {
    int rc, i;
    for (i = 0; i < 15; ++i) {
        rc = pthread_create(&thread_id[i], NULL, print, i);
        sleep(1);
    }
    pthread_exit(NULL);
}