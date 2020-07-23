#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

main() {
  char c;

  c = CHAR_MIN;
  do {
    printf("%d\n", c);
    c = c+1;
  } while (c < CHAR_MAX);

  exit(EXIT_SUCCESS);
}
