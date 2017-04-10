#include <stdio.h>
#include <stdlib.h>
#define DELTA 0.0001
main(){
      double sq_root(double); /* prototype */
      int i;

      for(i = 1; i < 100; i++){
              printf("root of %d is %f\n", i, sq_root(i));
      }
      exit(EXIT_SUCCESS);
}

double
sq_root(double x){      /* definition */
      double curr_appx, last_appx, diff;

      last_appx = x;
      diff = DELTA+1;

      while(diff > DELTA){
              curr_appx = 0.5*(last_appx
                      + x/last_appx);
              diff = curr_appx - last_appx;
              if(diff < 0)
                      diff = -diff;
              last_appx = curr_appx;
      }
      return(curr_appx);
}