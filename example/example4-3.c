#include <stdio.h>
#include <stdlib.h>

main(){
      void pmax(int first, int second);       /*declaration*/
      int i,j;
      for(i = -10; i <= 10; i++){
              for(j = -10; j <= 10; j++){
                      pmax(i,j);
              }
      }
      exit(EXIT_SUCCESS);
}

void
pmax(int a1, int a2){                           /*definition*/
      int biggest;

      if(a1 > a2){
              biggest = a1;
      }
      else{
              biggest = a2;
      }

      printf("largest of %d and %d is %d\n",
              a1, a2, biggest);
}