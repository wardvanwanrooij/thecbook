/* first file */

int i; /* definition */
main () {
  void f_in_other_place (void);   /* declaration */
  i = 0;
}
/* end of first file */


/* start of second file */

extern int i; /* declaration */
void f_in_other_place (void) {   /* definition */
  i++;
}
/* end of second file */
