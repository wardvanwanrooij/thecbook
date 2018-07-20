#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

main() {
  size_t sz;
  sz = sizeof(sz);
  printf("size of sizeof is %lu\n",
	 (unsigned long)sz);
  exit(EXIT_SUCCESS);
}
