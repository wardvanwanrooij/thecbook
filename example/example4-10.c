/* example library module */
/* only 'callable' is visible outside */
static buf [100];
static length;
static void fillup(void);

int
callable (){
      if (length ==0){
              fillup ();
      }
      return (buf [length--]);
}

static void
fillup (void){
      while (length <100){
              buf [length++] = 0;
      }
}