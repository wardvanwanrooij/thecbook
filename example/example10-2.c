/*
* options() parses option letters and option arguments from the argv list.
* Succesive calls return succesive option letters which match one of
* those in the legal list. Option letters may require option arguments
* as indicated by a ':' following the letter in the legal list.
* for example, a legal list of "ab:c" implies that a, b and c are
* all valid options and that b takes an option argument. The option
* argument is passed back to the calling function in the value
* of the global OptArg pointer. The OptIndex gives the next string
* in the argv[] array that has not already been processed by options().
*
* options() returns -1 if there are no more option letters or if
* double SwitchChar is found. Double SwitchChar forces options()
* to finish processing options.
*
* options() returns '?' if an option not in the legal set is
* encountered or an option needing an argument is found without an
* argument following it.
*
*/

#include <stdio.h>
#include <string.h>

static const char SwitchChar = '-';
static const char Unknown = '?';

int OptIndex = 1;       /* first option should be argv[1] */
char *OptArg = NULL;    /* global option argument pointer */

int options(int argc, char *argv[], const char *legal)
{
        static char *posn = "";  /* position in argv[OptIndex] */
        char *legal_index = NULL;
        int letter = 0;

        if(!*posn){
                /* no more args, no SwitchChar or no option letter ? */
                if((OptIndex >= argc) ||
                        (*(posn = argv[OptIndex]) != SwitchChar) ||
                        !*++posn)
                                return -1;
                /* find double SwitchChar ? */
                if(*posn == SwitchChar){
                        OptIndex++;
                        return -1;
                }
        }
        letter = *posn++;
        if(!(legal_index = strchr(legal, letter))){
                if(!*posn)
                        OptIndex++;
                return Unknown;
        }
        if(*++legal_index != ':'){
                /* no option argument */
                OptArg = NULL;
                if(!*posn)
                        OptIndex++;
        } else {
                if(*posn)
                        /* no space between opt and opt arg */
                        OptArg = posn;
                else
                        if(argc <= ++OptIndex){
                                posn = "";
                                return Unknown;
                        } else
                                OptArg = argv[OptIndex];
                posn = "";
                OptIndex++;
        }
        return letter;
}