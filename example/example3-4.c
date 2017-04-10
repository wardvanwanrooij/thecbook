#include <stdio.h>
#include <stdlib.h>
main(){
      int i;

      i = 0;
      while(i <= 10){
              printf("%d\n", i);
              i++;
      }

      /* the same done using ``for'' */
      for(i = 0; i <= 10; i++){
              printf("%d\n", i);
      }
      exit(EXIT_SUCCESS);
}