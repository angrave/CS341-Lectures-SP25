#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define N 10
int starting_value[N];
pthread_t tid[N]; 

void* myfunc(void*ptr) {
  
  printf("My thread id is %p and I'm starting at %d\n",pthread_self(), myvalue);

  return NULL;
}
int main() {
  puts("Experiment 1: pthread_create( &tid[i], 0, myfunc, & i )");
  
  for(int i =0; i < N; i++) {
     pthread_create( &tid[i],NULL, myfunc, & i );
  }
  
  for(int i =0; i < N; i++) {
    pthread_join(tid[i],NULL);
  }
  
  //("Experiment 2: pthread_create(&tid[i],NULL, myfunc, & starting_value[i] );");
  
  
  
  //("Experiment 3: pthread_create & immediately pthread_join");
  
  
  
  pthread_exit(NULL) ; // this is a one way trip - never returns !!!!!!!!!
  return 0;
}

