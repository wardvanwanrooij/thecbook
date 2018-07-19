#include <stdio.h>
#include <stdlib.h>

main() {
  union {
    float u_f;
    int u_i;
  } var;

  var.u_f = 23.5;
  printf("value is %f\n", var.u_f);
  var.u_i = 5;
  printf("value is %d\n", var.u_i);
  exit(EXIT_SUCCESS);
}
