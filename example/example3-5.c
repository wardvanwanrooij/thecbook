#include <stdio.h>
#include <stdlib.h>

main(){
      int i;
      for(i = 0; i <= 10; i++){
              switch(i){
                      case 1:
                      case 2:
                              printf("1 or 2\n");
                      case 7:
                              printf("7\n");
                      default:
                              printf("default\n");
              }
      }
      exit(EXIT_SUCCESS);
}