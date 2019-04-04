#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	sigset_t signalset;
	sigaddset(&signalset, SIGINT);
    int i=0;
    for(i=0;i<5;i++)
    {
      printf("%d\n",(i+1));
      sleep(1);
    }
    sigprocmask(SIG_UNBLOCK, &signalset, NULL);
    while(i<10)
    {
      printf("%d\n", (i+1));
      sleep(1);
      i++;
    }
    
}
