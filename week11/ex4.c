#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(void) {
 int f1 = open("ex1.txt", O_RDWR, 0);
 int f2 = open("ex1.memcpy.txt", O_RDWR, 0);
 
 struct stat fstat;
 fstat(f1, &fstat);
 
 size_t size = fstat.st_size;
 ftruncate(f2, size);
 
 char* adr1 = mmap(0, size, PROT_READ, MAP_SHARED, f1, 0);
 char* adr2 = mmap(0, size, PROT_READ|PROT_WRITE, MAP_SHARED, f2, 0);
 
 memcpy(adr2, adr1, size);
 

 close(f1);
 close(f2);
}