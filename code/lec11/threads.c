#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void* myevilfunc(void* unused) {
  sleep(1);
  printf("Hello!\n");
  sleep(1);
  pthread_exit( (void*) 0xCafecafe);
  return (void*)0xBaadF00d;
}

int main() {
  pthread_t threadid;
  pthread_create(&threadid, NULL, myevilfunc, "Bones");
  
  void* result;
  pthread_join(threadid, &result); // like waitpid
  printf("Result %p\n", result);
  printf("World!\n");

  return 0;
}
