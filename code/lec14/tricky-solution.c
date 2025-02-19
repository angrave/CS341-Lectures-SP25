#include <stdio.h>
#include <pthread.h>

pthread_t tid1,tid2;
pthread_mutex_t m ; 



void* myfunc2(void*param) {
 int* counter = (int*)param;
 for(int i=0; i < 1000000;i++) {
   //.printf("%p I want the duck!\n", pthread_self());
   pthread_mutex_lock( &m );
   (*counter) +=1;
   
 }
 return NULL;
}

int main() {
 int counter=0;
 pthread_create(&tid1, 0, myfunc2, &counter);
 pthread_create(&tid2, 0, myfunc2, &counter);
 pthread_join(tid1,NULL);
 pthread_join(tid2,NULL);
 printf("%d\n", counter );
return 0;
}
