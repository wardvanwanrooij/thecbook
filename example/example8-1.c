#include <stdio.h>
#include <stdlib.h>

void func(register int arg1, double arg2);

main(){
      func(5, 2);
      exit(EXIT_SUCCESS);
}

/*
* Function illustrating that formal parameters
* may be declared to have register storage class.
*/
void func(register int arg1, double arg2){

      /*
       * Illustrative only - nobody would do this
       * in this context.
       * Cannot take address of arg1, even if you want to
       */
      double *fp = &arg2;

      while(arg1){
              printf("res = %f\n", arg1 * (*fp));
              arg1--;
      }
}