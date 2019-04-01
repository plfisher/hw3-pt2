
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

