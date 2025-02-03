#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {
   puts("What run now? Uh?");
   char* line = NULL;
   size_t size = 0;
   size = getline(&line, &size, stdin);
   line[size-1] = 0; // '\0';
   printf("about to exec <%s>!\n", line);
   execlp(line,line, NULL);
   perror("exec failed");
   return 0;
}
