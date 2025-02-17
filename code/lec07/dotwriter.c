#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

void lucy(int signal) {
  write(1,"Wake up !", 265);
}
void polo(int signal) {
  char mesg[] = "Stop pressing CTRL -C . This is your only warning";
  write(1,mesg,sizeof(mesg));
  
}
int main() {
  signal(SIGALRM, lucy );
  signal(SIGINT, polo );
  // alarm(5);
  printf("My pid is %d\n", getpid() );
  int i = 60;
  while(--i) { 
    write(1, ".",1);
    sleep(1);
    if(i == 57) {
      kill( getpid() , SIGINT);
      raise(SIGKILL); // == kill(getpid(),...)
    }
  }
  write(1, "Done!",5);
  return 0;
}
