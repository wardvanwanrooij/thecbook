/* example of a single source file layout */
#include <stdio.h>

/* Things with external linkage:
* accessible throughout program.
* These are declarations, not definitions, so
* we assume their definition is somewhere else.
*/

extern int important_variable;
extern int library_func(double, int);

/*
* Definitions with external linkage.
*/
extern int ext_int_def = 0;     /* explicit definition */
int tent_ext_int_def;           /* tentative definition */

/*
* Things with internal linkage:
* only accessible inside this file.
* The use of static means that they are also
* tentative definitions.
*/

static int less_important_variable;
static struct{
        int member_1;
        int member_2;
}local_struct;

/*
* Also with internal linkage, but not a tentative
* definition because this is a function.
*/
static void lf(void);

/*
* Definition with internal linkage.
*/
static float int_link_f_def = 5.3;

/*
* Finally definitions of functions within this file
*/

/*
* This function has external linkage and can be called
* from anywhere in the program.
*/
void f1(int a){}

/*
* These two functions can only be invoked by name from
* within this file.
*/
static int local_function(int a1, int a2){
        return(a1 * a2);
}

static void lf(void){
        /*
         * A static variable with no linkage,
         * so usable only within this function.
         * Also a definition (because of no linkage)
         */
        static int count;
        /*
         * Automatic variable with no linkage but
         * an initializer
         */
        int i = 1;

        printf("lf called for time no %d\n", ++count);
}
/*
* Actual definitions are implicitly provided for
* all remaining tentative definitions at the end of
* the file
*/