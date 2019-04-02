#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shell_loop();
char *shell_read_line(void);
char **shell_split_line(char *line);
int shell_execute(char **args);


sigset_t signalset;
int main(int argc, char **argv)
{
  
  sigaddset(&signalset, SIGINT);
  
  sigprocmask(SIG_BLOCK, &signalset, NULL);
  shell_loop();
  
  
}

void shell_loop()
{
  char *line;
  char **args;
  int status;

  do {
    printf("shell> ");
    line = shell_read_line();
    args = shell_split_line(line);
    status = shell_execute(args);

    free(line);
    free(args);
  } while (status);
}

char *shell_read_line(void)
{
  char *line = NULL;
  ssize_t bufsize = 0; // have getline allocate a buffer for us
  getline(&line, &bufsize, stdin);
  return line;
}

char **shell_split_line(char *line)
{
  int buffersize=64;
  int i=0;
  char **args=malloc(buffersize*sizeof(char*));
  char *arg;
  
  arg=strtok(line, " \t\r\n\a");
  while(arg!=NULL)
  {
    args[i]=arg;
    i++;
    
    if(i>= buffersize)
    {
      buffersize+=64;
      args=realloc(args, buffersize *sizeof(char*));
      
    }
     arg=strtok(NULL, " \t\r\n\a");
  }
 args[i]=NULL;
 return args; 
}

int shell_execute(char **args)
{
  int i;
  
  if(args[0]==NULL)
  {
    return 1;
  }
  
  if(strcmp(args[0],"exit")==0)
  {
    return 0;
  }
  else if(strcmp(args[0],"run")==0)
  {
    pid_t pid=fork();
    if(pid==0)
    {
      argv[0]="./child";
      execv(argv[0], argv);
      perror("execv");
    }
    
      return 1;
  }
 
  
}

