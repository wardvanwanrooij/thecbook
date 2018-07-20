#include <stdio.h>
#include <stdlib.h>
main() {
  int i;
  unsigned int stop_val;

  stop_val = 0;
  i = -10;

  while (i <= stop_val) {
    printf("%d\n", i);
    i = i + 1;
  }
  exit(EXIT_SUCCESS);
}
