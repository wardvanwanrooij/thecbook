#include <stdio.h>
#include <stdlib.h>

main(){
      int i;

      for(i=0; i <= 10; i++){
              printf((i&1) ? "odd\n" : "even\n");
      }
      exit(EXIT_SUCCESS);
}