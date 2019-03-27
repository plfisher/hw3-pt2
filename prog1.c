#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <unistd.h>

int main(int argc, char** argv) {
int t1 = 0, t2 = 1, nextTerm = 0, n;
  
  char * numchar=(*(argv+1));
  int num=atoi(numchar);
  fork();
  for (i = 1; i <= n; ++i)
    {
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
  
  if (fork() == 0) 
  {
    printf("%d", t2%10)
  }
  
}
