#include <stdio.h>
#include <stdlib.h>

main(){
      int x,y;
      x = 0; y = ~0;

      while(x != y){
              printf("%x & %x = %x\n", x, 0xff, x&0xff);
              printf("%x | %x = %x\n", x, 0x10f, x|0x10f);
              printf("%x ^ %x = %x\n", x, 0xf00f, x^0xf00f);
              printf("%x >> 2 = %x\n", x, x >> 2);
              printf("%x << 2 = %x\n", x, x << 2);
              x = (x << 1) | 1;
      }
      exit(EXIT_SUCCESS);
}