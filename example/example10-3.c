/*
* Simple program to print lines from a text file which contain
* the "word" supplied on the command line.
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
* Declarations for the pattern program
*
*/

#define CFLAG 0x001     /* only count the number of matching lines */
#define IFLAG 0x002     /* ignore case of letters */
#define LFLAG 0x004     /* show line numbers */
#define NFLAG 0x008     /* show input file names */
#define VFLAG 0x010     /* show lines which do NOT match */

extern int OptIndex;    /* current index into argv[] */
extern char *OptArg;    /* global option argument pointer */

/*
* Fetch command line switches from arguments to main()
*/

int options(int, char **, const char *);

/*
* Record the required options ready to control program beaviour
*/

unsigned set_flags(int, char **, const char *);

/*
* Check each line of the input file for a match
*/

int look_in(const char *, const char *, unsigned);

/*
* Print a line from the input file on the standard output
* in the format specified by the command line switches
*/

void print_line(unsigned mask, const char *fname,
                int lnno, const char *text);


static const char
                /* Legal options for pattern */
        *OptString = "cilnv",
                /* message when options or arguments incorrect */
        *errmssg = "usage: pattern [-cilnv] word [filename]\n";

int main(int argc, char *argv[])
{
        unsigned flags = 0;
        int success = 0;
        char *search_string;

        if(argc < 2){
                fprintf(stderr, errmssg);
                exit(EXIT_FAILURE);
        }

        flags = set_flags(argc, argv, OptString);

        if(argv[OptIndex])
                search_string = argv[OptIndex++];
        else {
                fprintf(stderr, errmssg);
                exit(EXIT_FAILURE);
        }

        if(flags & IFLAG){
                /* ignore case by dealing only with lowercase */
                char *p;
                for(p = search_string ; *p ; p++)
                        if(isupper(*p))
                                *p = tolower(*p);
        }

        if(argv[OptIndex] == NULL){
                /* no file name given, so use stdin */
                success = look_in(NULL, search_string, flags);
        } else while(argv[OptIndex] != NULL)
                success += look_in(argv[OptIndex++],
                                search_string, flags);

        if(flags & CFLAG)
                printf("%d\n", success);

        exit(success ? EXIT_SUCCESS : EXIT_FAILURE);
}

unsigned set_flags(int argc, char **argv, const char *opts)
{
        unsigned flags = 0;
        int ch = 0;

        while((ch = options(argc, argv, opts)) != -1){
                switch(ch){
                        case 'c':
                                flags |= CFLAG;
                                break;
                        case 'i':
                                flags |= IFLAG;
                                break;
                        case 'l':
                                flags |= LFLAG;
                                break;
                        case 'n':
                                flags |= NFLAG;
                                break;
                        case 'v':
                                flags |= VFLAG;
                                break;
                        case '?':
                                fprintf(stderr, errmssg);
                                exit(EXIT_FAILURE);
                }
        }
        return flags;
}


int look_in(const char *infile, const char *pat, unsigned flgs)
{
        FILE *in;
        /*
         * line[0] stores the input line as read,
         * line[1] is converted to lower-case if necessary
         */
        char line[2][BUFSIZ];
        int lineno = 0;
        int matches = 0;

        if(infile){
                if((in = fopen(infile, "r")) == NULL){
                        perror("pattern");
                        return 0;
                }
        } else
                in = stdin;

        while(fgets(line[0], BUFSIZ, in)){
                char *line_to_use = line[0];
                lineno++;
                if(flgs & IFLAG){
                        /* ignore case */
                        char *p;
                        strcpy(line[1], line[0]);
                        for(p = line[1] ; *p ; *p++)
                                if(isupper(*p))
                                        *p = tolower(*p);
                        line_to_use = line[1];
                }

                if(strstr(line_to_use, pat)){
                        matches++;
                        if(!(flgs & VFLAG))
                                print_line(flgs, infile, lineno, line[0]);
                } else if(flgs & VFLAG)
                        print_line(flgs, infile, lineno, line[0]);
        }
        fclose(in);
        return matches;
}

void print_line(unsigned mask, const char *fname,
                        int lnno, const char *text)
{
        if(mask & CFLAG)
                return;
        if(mask & NFLAG)
                printf("%s:", *fname ? fname : "stdin");
        if(mask & LFLAG)
                printf(" %d :", lnno);
        printf("%s", text);
}