#include <stdio.h>
#include <stdlib.h>
void
date(int *, int *);     /* declare the function */

main() {
  int month, day;
  date(&day, &month);
  printf("day is %d, month is %d\n", day, month);
  exit(EXIT_SUCCESS);
}

void
date(int *day_p, int *month_p) {
  int day_ret, month_ret;
  /*
   * At this point, calculate the day and month
   * values in day_ret and month_ret respectively.
   */
  *day_p = day_ret;
  *month_p = month_ret;
}
