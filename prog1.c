#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <unistd.h>
#include <math.h>
#include <sys/wait.h>
#include <signal.h>

void handler(int sig);
pid_t Fork(void);

int main(int argc, char** argv) {

  
  char * numchar=(*(argv+1));
  int num=atoi(numchar);
  
  pid_t pid=Fork();
  if(pid==0)
  {
  int gnum=(1+sqrt(5))/2;
    int numerator=(pow(gnum, num))-(pow((1-gnum), num));
    int result=round(numerator/sqrt(5));
    exit(result);
  }
  else
  {
    signal(SIGCHLD, handler);
    int returnval=WIFEXITED(pid);
    printf("%d", returnval);
  }

pid_t Fork(void)
{
  pid_t pid;
  
  if((pid=fork())<0)
    perror("Fork error");
  return pid;
}
  
void handler(int sig)
{
  pid_t pid;
  pid=wait(NULL);
}
