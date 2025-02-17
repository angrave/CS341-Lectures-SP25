#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int a = 10;
  int* ptr = &a;

  pid_t child = fork();
  
  if(child == 0) { 
    * ptr = 20;
    ptr = NULL;
  } else { 
    waitpid(child, NULL,0); 
    printf("%d", * ptr );
  }

  return 0;
}
