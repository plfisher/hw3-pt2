#include <stdio.h>
int main(int argc, char** argv) {

  int num=*(*(argv+1));
  printf("%d", num);
  
}
