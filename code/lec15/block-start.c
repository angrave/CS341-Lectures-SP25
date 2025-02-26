#include <pthread.h>
#include <stdio.h>

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cv = PTHREAD_COND_INITIALIZER;
double array[10];
int n = 0;

void push(double v) { // blocks while full (n ==10)
 array[n++] = v;
  
}


double pop() { // blocks while empty (n == 0)
  double v = array[--n];
  return v;
}
// Test with 2 threads that produce values...
void* producer(void*arg){
   for(int i =0; i < 10000; i++)
      push(i);
  return NULL;
}
// And one thread that consume values
void* consumer(void*arg) {
  double sum  = 0;
  
  for(int remain = ; remain; remain --) { 
    sum += pop(); 
  }
  
  printf("%.0f\n", sum);
  // we  know sum i 0...9999 is N (N+1) /2 but drop the /2 because 2 threads
  // so expect a total of 99990000
  
  return NULL;
}

int main() {
  pthread_t tid1, tid2, tid3;
  pthread_create(&tid1, NULL, producer, NULL);
  pthread_create(&tid2, NULL, producer, NULL);
  pthread_create(&tid3,NULL, consumer, NULL);
  
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  pthread_join(tid3, NULL);
  
  return 0;
}
