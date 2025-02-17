#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char * compiler = "gcc";
  
int main(int argc, char** argv) {
	  if(argc != 2) {
	    fprintf(stderr,"%s prog.c\n",argv[0]);
	    exit(1); 
	  }
	  char* target = argv[1];

	  while(1) {
	    pid_t child = fork();

	    if(child ==0){ // I'm the child 

// Gotcha
//1. Executable name must be listed twice (once as the file to execute, second time is part of the arguments to main)
//2. Terminate list of arguments with (const char*)NULL

        execlp(
        
	      perror(compiler); 
	      exit(1);
	    }
//Hint: WEXITSTATUS(status)  will tell us the exit value of gcc (provided WIFEXITED(status) is nonzero)

	    ?
	    sleep(5);
	  }
	  puts("running your program"); // output to a terminal and puts includes a newline so this is immediately flushed :-)

	  execlp("./a.out","./a.out",(const char*)NULL);
	  perror("Failed to run ./a.out");
	  return 1;
}
