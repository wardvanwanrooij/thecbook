#include <stdio.h>
#include <stdlib.h>

main(){
      int i,j;
      float f;

      i = 5; j = 2;
      f = 3.0;

      f = f + j / i;
      printf("value of f is %f\n", f);
      exit(EXIT_SUCCESS);
}