#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char**argv) {
  if(argc != 2) {
     fprintf(stderr,"Usage: %s filename\n", argv[0]);
     exit(21);
   }

  FILE* file = fopen(argv[1], "r"); // may return NULL 
  if(!file) { perror("Aggggh!"); exit(1);}
  
  char* line = NULL;
  size_t capacity = 0;
  ssize_t bytesread;
  int linenumber = 0;
  while(1) {
    bytesread = getline( &line, &capacity, file);
    if(bytesread == -1) break;
    printf("%3d: %s", ++linenumber, line);
  }
  free(line); line = NULL;
  fclose(file); file = NULL;
  return 0;
}
