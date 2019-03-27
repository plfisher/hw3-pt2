#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv) {

  char * numchar=(*(argv+1));
  int num=atoi(numchar);
  printf("%d", num);
  
}
