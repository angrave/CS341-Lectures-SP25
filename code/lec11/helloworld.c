#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void* shout(void* arg) {
  printf("Address %p, as a string: %s\n", arg, (char*) arg);
  return strdup((char*) arg+1);
}

int main() {
  pthread_t tA, tB;
  
  pthread_create(&tA, NULL, shout, "Hello");

  pthread_create(&tB, NULL, shout, "World");
  void* result;
  pthread_join(tB, &result);
  printf("result is %s\n", (char*)result);
  free(result);
  pthread_join(tA, NULL);
  // HAVE FINISHED!!!!!
  return 0;
}