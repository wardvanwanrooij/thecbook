#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GROW_BY 10      /* string grows by 10 chars */

main() {
  char *str_p, *next_p, *tmp_p;
  int ch, need, chars_read;

  if (GROW_BY < 2) {
    fprintf(stderr,
	    "Growth constant too small\n");
    exit(EXIT_FAILURE);
  }

  str_p = (char *)malloc(GROW_BY);
  if (str_p == NULL) {
    fprintf(stderr,"No initial store\n");
    exit(EXIT_FAILURE);
  }

  next_p = str_p;
  chars_read = 0;
  while ((ch = getchar()) != EOF) {
    /*
     * Completely restart at each new line.
     * There will always be room for the
     * terminating zero in the string,
     * because of the check further down,
     * unless GROW_BY is less than 2,
     * and that has already been checked.
     */
    if (ch == '\n') {
      /* indicate end of line */
      *next_p = 0;
      printf("%s\n", str_p);
      free(str_p);
      chars_read = 0;
      str_p = (char *)malloc(GROW_BY);
      if (str_p == NULL) {
	fprintf(stderr,"No initial store\n");
	exit(EXIT_FAILURE);
      }
      next_p = str_p;
      continue;
    }
    /*
     * Have we reached the end of the current
     * allocation ?
     */
    if (chars_read == GROW_BY-1) {
      *next_p = 0;    /* mark end of string */
                      /*
                       * use pointer subtraction
                       * to find length of
                       * current string.
                       */
      need = next_p - str_p +1;
      tmp_p = (char *)malloc(need+GROW_BY);
      if (tmp_p == NULL) {
	fprintf(stderr,"No more store\n");
	exit(EXIT_FAILURE);
      }
      /*
       * Copy the string using library.
       */
      strcpy(tmp_p, str_p);
      free(str_p);
      str_p = tmp_p;
      /*
       * and reset next_p, character count
       */
      next_p = str_p + need-1;
      chars_read = 0;
    }
    /*
     * Put character at end of current string.
     */
    *next_p++ = ch;
    chars_read++;
  }
  /*
   * EOF - but do unprinted characters exist?
   */
  if (str_p - next_p) {
    *next_p = 0;
    fprintf(stderr,"Incomplete last line\n");
    printf("%s\n", str_p);
  }
  exit(EXIT_SUCCESS);
}
