#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
#include <string.h>

int main(){

	time_t start = time(NULL);
	int i = 1;

	while((time(NULL) - start) < 10){
		int n = 1024 * 10 * sizeof(char);
		void * ptr = malloc(n);
		memset(ptr, '0', n);
		i++;
		sleep(1);
	}

	return 0;
}