#include <stdio.h>
#include <stdlib.h>

/*
 * Illustrates casts.
 * For each of the numbers between 2 and 20,
 * print the percentage difference between it and the one before. 
 */
main() {
  int curr_val;
  float temp, pcnt_diff;

  curr_val = 2;
  while (curr_val <= 20 ){
    /*
     * % difference is 1/(curr_val)*100
     */
    temp = curr_val;
    pcnt_diff = 100/temp;
    printf("Percent difference at %d is %f\n",
	   curr_val, pcnt_diff);
    /*
     * Or, using a cast:
     */
    pcnt_diff = 100/(float)curr_val;
    printf("Percent difference at %d is %f\n",
	   curr_val, pcnt_diff);
    curr_val = curr_val + 1;
  }
  exit(EXIT_SUCCESS);
}
