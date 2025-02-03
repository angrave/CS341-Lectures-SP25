#include <unistd.h>
#include <stdio.h>
// powerful ls ..
int main(int argc, char**argv) {
   //xxexecp("clang"/* path to program*/ , "clang" , "a.c" , "-o","jhsdfjsh", NULL);
   printf("Executing %s ...\n", *(argv+1) ); // argv[1]
   execvp( argv[1], argv + 2);
   perror("Failed to be all powerful");
}
