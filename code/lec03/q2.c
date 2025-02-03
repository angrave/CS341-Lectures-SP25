#include <stdio.h>
int main(int argc, char**argv) {
  
  char ** p = argv;
  while(*p) {
    //or printf("%s\n", *p);
    puts(*p++);
    //p ++;
  }
  return 0;
}