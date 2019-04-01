#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <unistd.h>
#include <math.h>
#include <sys/wait.h>
#include <signal.h>

void handler(int sig);
pid_t Fork(void);
typedef long long int longlongint;

int main(int argc, char** argv) {

  
  char * numchar=(*(argv+1));
  int num=atoi(numchar);
  pid_t pid=Fork();
  if(pid==0)
  {
    longlongint f[60];
    f[0]=0;
    f[1]=1;
    longlongint i=0;
    for(i=2;i<=60;i++)
    {
      f[i]=(f[i-1]+f[i-2])%10;
    }
    printf("%d\n", f[num%60]);
    printf("\n");
    exit(f[num%60]);
  }
  else
  {
    int status;
    signal(SIGCHLD, handler);
    waitpid(pid, &status, 0); 
  
    if ( WIFEXITED(status) ) 
    { 
        int exit_status = WEXITSTATUS(status);         
        printf("%d\n", exit_status); 
    } 
  }
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
