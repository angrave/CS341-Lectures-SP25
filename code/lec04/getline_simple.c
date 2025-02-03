#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char**argv) {

  char * buffer = NULL;
  size_t buf_capacity = 0;
  
  while(1) {
   ssize_t result = getline( &buffer, &buf_capacity, stdin);
   printf("result is %d at %p. Contents=%s", (int)result, buffer, buffer );
   if( result <= 0) break;
   if( buffer[result-1] == '\n' ) { 
     buffer[ result -1 ] = '\0';
   }
  }
  free(buffer); buffer = NULL;
  return 0;
}
