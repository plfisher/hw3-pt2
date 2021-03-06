#define LSH_RL_BUFSIZE 1024
#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void lsh_loop(void);
char *lsh_read_line(void);
char **lsh_split_line(char *line);
int lsh_launch(char **args);
int lsh_execute(char **args);

int main(int argc, char **argv)
{
  lsh_loop();
  
  
}

void lsh_loop(void)
{
  char *line;
  char **args;
  int status;

  do {
    printf("shell> ");
    line = lsh_read_line();
    args = lsh_split_line(line);
    status = lsh_execute(args);

    free(line);
    free(args);
  } while (status);
}

char *lsh_read_line(void)
{
  char *line = NULL;
  ssize_t bufsize = 0; // have getline allocate a buffer for us
  getline(&line, &bufsize, stdin);
  return line;
}
char **lsh_split_line(char *line)
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

int lsh_launch(char **args)
{
  pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid == 0) {
    // Child process
    if (execvp(args[0], args) == -1) {
      perror("lsh");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    // Error forking
    perror("lsh");
  } else {
    // Parent process
    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}

int shell_cd(char **args)
{
  if(args[1]==NULL)
  {
    fprintf(stderr, "shell: expected argument to \"cd\"\n");
  }
  else {
    if(chdir(args[1])!=0)
    {
      perror("lsh");
    }
  }
  return 1;
}

int shell_help(char **args)
{
  int i;
  printf("Type a command to be executed\n");
  return 1;
}

int shell_exit(char **args)
{
  return 0;
}

int checkbuiltins(char **args)
{
    if(strcmp(args[0], "help")==0)
    {
      shell_help(args);
      return 1;
    }
    else if (strcmp(args[0],"cd")==0)
    {
      shell_cd(args);
      return 1;
    }
    else if(strcmp(args[0],"exit")==0)
    {
      shell_exit(args);
      return 0;
    }
    else
      return 2;
}

int lsh_execute(char **args)
{
  int i;
  
  if(args[0]==NULL)
  {
    return 1;
  }
  
  if(checkbuiltins(args)==1)
    return 1;
  else if(checkbuiltins(args)==0)
    return 0;
  else
  return lsh_launch(args);
}
