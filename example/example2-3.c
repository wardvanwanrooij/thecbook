#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

main() {
  char c;

  c = CHAR_MIN;
  /* does not reach CHAR_MAX but with "c <= CHAR_MAX" no termination. */
  while (c != CHAR_MAX) {
    printf("%d\n", c);
    c = c+1;
  }

  exit(EXIT_SUCCESS);
}
