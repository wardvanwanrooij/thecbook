#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTRING       50      /* max no. of strings */
#define MAXLEN          80      /* max length. of strings */

void print_arr(const char *p_array[]);
void sort_arr(const char *p_array[]);
char *next_string(char *destination);

main() {
  /* leave room for null at end */
  const char *p_array[MAXSTRING+1];

  /* storage for strings */
  char strings[MAXSTRING][MAXLEN];

  /* count of strings read */
  int nstrings;

  nstrings = 0;
  while (nstrings < MAXSTRING &&
	 next_string(strings[nstrings]) != 0) {

    p_array[nstrings] = strings[nstrings];
    nstrings++;
  }
  /* terminate p_array */
  p_array[nstrings] = 0;

  sort_arr(p_array);
  print_arr(p_array);
  exit(EXIT_SUCCESS);
}

void print_arr(const char *p_array[]) {
  int index;
  for (index = 0; p_array[index] != 0; index++)
    printf("%s\n", p_array[index]);
}

void sort_arr(const char *p_array[]) {
  int comp_val, low_index, hi_index;
  const char *tmp;

  for (low_index = 0;
       p_array[low_index] != 0 &&
	 p_array[low_index+1] != 0;
       low_index++) {

    for (hi_index = low_index+1;
	 p_array[hi_index] != 0;
	 hi_index++){

      comp_val=strcmp(p_array[hi_index],
		      p_array[low_index]);
      if (comp_val >= 0)
	continue;
      /* swap strings */
      tmp = p_array[hi_index];
      p_array[hi_index] = p_array[low_index];
      p_array[low_index] = tmp;
    }
  }
}

char *next_string(char *destination) {
  char *cp;
  int c;

  cp = destination;
  while ((c = getchar()) != '\n' && c != EOF) {
    if (cp-destination < MAXLEN-1)
      *cp++ = c;
  }
  *cp = 0;
  if (c == EOF && cp == destination)
    return(0);
  return(destination);
}
