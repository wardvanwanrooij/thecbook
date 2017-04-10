#include <stdio.h>
#include <stdlib.h>
main(){
      void pmax();                    /* declaration */
      int i,j;
      for(i = -10; i <= 10; i++){
              for(j = -10; j <= 10; j++){
                      pmax(i,j);
              }
      }
      exit(EXIT_SUCCESS);
}
/*
* Function pmax.
* Returns:      void
* Prints larger of its two arguments.
*/
void
pmax(int a1, int a2){                   /* definition */
      int biggest;

      if(a1 > a2){
              biggest = a1;
      }else{
              biggest = a2;
      }

      printf("larger of %d and %d is %d\n",
              a1, a2, biggest);
}