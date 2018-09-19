#include <stdio.h>
#include <time.h>
#include <pthread.h>
int count = 0;
char buffer[100];
time_t start;
int i = 0;
pthread_mutex_t mut;
pthread_cond_t c, p;

void *producer(void *ptr)
{

 while (1) { 
  pthread_mutex_lock(&mut);
  
  if (count == 100){
   pthread_cond_wait(&p, &mut);
  }
  buffer[count] = 'p';
  count = count + 1;
  time_t end = time(NULL);
  double fraction = (double)(end - start);

  if(fraction > i*60){
   printf("Time of execution:%f\n", ((double)(end - start)));
   i++;
  }

  if (count == 1){
   pthread_cond_signal(&c);
   pthread_mutex_unlock(&mut);
  }
 }
}

void *consumer(void *ptr)
{
 while (1) {
  pthread_mutex_lock(&mut);
  if (count == 0){
    pthread_cond_wait(&c, &mut);
  }
  buffer[count] = 'c';
  count = count - 1;
  if (count == 99){
   pthread_cond_signal(&p);
   pthread_mutex_unlock(&mut);
  }
 }
}


int main(){
    return 0;
}