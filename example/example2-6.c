#include <stdio.h>
#include <stdlib.h>

main() {
  unsigned int x;
  x = 0;
  while (x >= 0) {
    printf("%d\n", x);
    x = x+1;
  }

  exit(EXIT_SUCCESS);
}
