#include <string.h>
#include <stdio.h>

void mystrcat(char* dst, const char* src) {

  // move past abc
  //
  // while (*dst) dst++;
  dst += strlen(dst);
  
  while( *src ) {
    *dst = *src;
  
    dst++;
    src++;
  }
  *dst = '\0';
}

int main(int argc, char** argv) {

  char dest[16];
  dest[0] = 'x'; 
  dest[1] = '\0'; // 0

  char* source = "DEF";
  mystrcat(dest, source);
  printf("Result is %s\n",dest);
  return 0;
}
