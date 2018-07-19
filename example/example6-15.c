#include <stdio.h>
#include <stdlib.h>

struct s {
  int a;
  char b;
  char *cp;
} ex_s = {1, 'a', "hello"};

main() {
  struct s first = ex_s;
  struct s second = {2, 'b', "byebye" };

  exit(EXIT_SUCCESS);
}
