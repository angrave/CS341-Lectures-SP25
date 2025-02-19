#include <stdio.h>
#include <pthread.h>

pthread_t tid1,tid2;
pthread_mutex_t duck  =PTHREAD_MUTEX_INITIALIZER;
  
// 

void* myfunc2(void*param) {
  int* counter = (int*) param;
 int i = 0; // stack variable
 for(; i < 1000000;i++) {
   // printf("I am thread %p and my value of i is %d\n", (void*)pthread_self(), i);
   pthread_mutex_lock( &duck);
   (*counter) +=1;
   pthread_mutex_unlock( &duck);
 }
 return NULL;
}

int main() {
 int count = 0;
  
 pthread_create(&tid1, 0, myfunc2, &count);
 pthread_create(&tid2, 0, myfunc2, &count);
 pthread_join(tid1,NULL);
 pthread_join(tid2,NULL);
 printf("%d\n", count );
return 0;
}
