#include <stdio.h>
#include <stdlib.h>
main(){
      void changer(int);
      int i;

      i = 5;
      printf("before i=%d\n", i);
      changer(i);
      printf("after i=%d\n", i);
      exit(EXIT_SUCCESS);
}

void
changer(int x){
      while(x){
              printf("changer: x=%d\n", x);
              x--;
      }
}