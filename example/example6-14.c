#include <stdio.h>
#include <stdlib.h>

#define NMONTHS 12

int month = 0;

short month_days[] =
  {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

char *mnames[] = {
		  "January", "February",
		  "March", "April",
		  "May", "June",
		  "July", "August",
		  "September", "October",
		  "November", "December"
};

main() {
  int day_count = month;

  for (day_count = month; day_count < NMONTHS;
      day_count++) {
    printf("%d days in %s\n",
	   month_days[day_count],
	   mnames[day_count]);
  }
  exit(EXIT_SUCCESS);
}
