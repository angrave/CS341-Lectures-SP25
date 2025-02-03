#include <stdio.h>

int main(int argc, char**argv) {
  int x = 10;
  int y;
  puts("Enter your two secret numbers"); // adds newline for you
  
  char mesg[10];
  char another[10];
  int result = scanf("%d;%d", &x , &y);
  
  // printf("mesg: %s and another:%s ", mesg, another);
  printf("x is now %d and y is now %d.\n", x, y);
  if( result != 2) {
    // handle the error
    puts("read the instructions!");
  } else {
     puts("Thanks");
  }
  return 0;
}
