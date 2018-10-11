#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>

int main(){

	time_t start = time(NULL);
	int second = 1;
	struct rusage r;

	while((time(NULL) - start) < 10){
		int mem_size = 1024 * 10 * sizeof(char);
		void * ptr = malloc(mem_size);
		memset(ptr, 0, mem_size);
		getrusage(RUSAGE_SELF, &r); 
		printf("%d second: Memory usage = %ld\n", second, r.ru_maxrss);
		second++;
		sleep(1);
	}

	return 0;
}