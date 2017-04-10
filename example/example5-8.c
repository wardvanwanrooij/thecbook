#include <stdio.h>
#include <stdlib.h>
main(){
      int i;
      char *cp;

      cp = "a string";
      while(*cp != 0){
              putchar(*cp);
              cp++;
      }
      putchar('\n');

      for(i = 0; i < 8; i++)
              putchar("a string"[i]);
      putchar('\n');
      exit(EXIT_SUCCESS);
}