#include <stdio.h>
#include <stdlib.h>

#define ARSIZE 10

struct wp_char {
  char wp_cval;
  short wp_font;
  short wp_psize;
} ar[ARSIZE];

void infun(struct wp_char *);

main() {
  struct wp_char wp_tmp, *lo_indx, *hi_indx, *in_p;

  for (in_p = ar; in_p < &ar[ARSIZE]; in_p++) {
    infun(in_p);
    if (in_p->wp_cval == '\n') {
      /* Leave the loop.
       * not incrementing in_p means that the
       * '\n' is ignored in the sort */
      break;
    }
  }

  /* Now a simple exchange sort.
   * We must be careful to avoid the danger of pointer underflow,
   * so check that there are at least two entries to sort. */
  if (in_p-ar > 1) for (lo_indx = ar; lo_indx <= in_p-2; lo_indx++) {
      for (hi_indx = lo_indx+1; hi_indx <= in_p-1; hi_indx++) {
	if (lo_indx->wp_cval > hi_indx->wp_cval) {
	  /* Swap the structures.  */
	  struct wp_char wp_tmp = *lo_indx;
	  *lo_indx = *hi_indx;
	  *hi_indx = wp_tmp;
	}
      }
    }

  /* now print */
  for (lo_indx = ar; lo_indx < in_p; lo_indx++) {
    printf("%c %d %d\n", lo_indx->wp_cval,
	   lo_indx->wp_font,
	   lo_indx->wp_psize);
  }
  exit(EXIT_SUCCESS);
}

void
infun(struct wp_char *inp) {
      inp->wp_cval = getchar();
      inp->wp_font = 2;
      inp->wp_psize = 10;
}
