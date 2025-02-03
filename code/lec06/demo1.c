#include <unistd.h>
#include <sys/wait.h>

#include <stdio.h>
#include <stdlib.h>


int main () {
  printf("Hello. My pid is %d\n", getpid());
  int abc = 456;
  int result  = fork();
  if(result ==0) {
    puts("I'm the child process.");
    execlp("ls", "ls", "/usr", NULL);
    printf("Hello. My pid is %d\n", getpid());
    * (int*) 0  = 0;
    exit(42);
  }
  printf("I'm the parent process my pid is %d and child is %d\n", getpid(), result);
  puts("Waiting....");
  int status;
  waitpid(result, &status, 0);
  printf("The raw status is %d\n", status);
  if( WIFEXITED(status) ) printf("Meaning of life is %d", WEXITSTATUS(status));
  if( WIFSIGNALED(status)) printf("SIgnalled %d\n", WTERMSIG(status));
  return 0;
}