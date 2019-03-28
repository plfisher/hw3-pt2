#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <unistd.h>

int main(int argc, char** argv) {
int t1 = 0, t2 = 1, nextTerm = 0, n;
  int i=0;
  int result;
  
  char * numchar=(*(argv+1));
  int num=atoi(numchar);
  n=num;
  pid=Fork();
  if(pid==0)
  {
  for (i = 1; i <= n; ++i)
    {
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
   result=t2%10;
  }
 
  
}

pid_t Fork(void)
{
  pid_t pid;
  
  if((pid=fork())<0)
    unix_error("Fork error");
  return pid;
}
