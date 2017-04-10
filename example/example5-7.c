/*
* Compare two strings for equality.
* Return 'false' if they are.
*/
int
str_eq(const char *s1, const char *s2){
      while(*s1 == *s2){
              /*
               * At end of string return 0.
               */
              if(*s1 == 0)
                      return(0);
              s1++; s2++;
      }
      /* Difference detected! */
      return(1);
}