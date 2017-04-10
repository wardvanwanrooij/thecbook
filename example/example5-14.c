#include <stdio.h>
#include <stdlib.h>

const char arr[] = "hello";
const char *cp = arr;
main(){

      printf("Size of arr %lu\n", (unsigned long)
                      sizeof(arr));
      printf("Size of *cp %lu\n", (unsigned long)
                      sizeof(*cp));
      exit(EXIT_SUCCESS);
}