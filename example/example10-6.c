/*
* Program to print the current ladder status.
*
*/

#include "player.h"

const char *ValidOpts = "f:";

const char *Usage = "usage: showlddr [-f ladder_file]\n";

char *OtherFile;

int main(int argc, char *argv[])
{
        int number;
        char ch;
        player *them;
        const char *fname;
        FILE *fp;

        if(argc == 3){
                while((ch = options(argc, argv, ValidOpts)) != -1){
                        switch(ch){
                                case 'f':
                                        OtherFile = OptArg;
                                        break;
                                case '?':
                                        fprintf(stderr, Usage);
                                        break;
                        }
                }
        } else if(argc > 1){
                fprintf(stderr, Usage);
                exit(EXIT_FAILURE);
        }

        fname = (OtherFile == 0)? LadderFile : OtherFile;
        fp = fopen(fname, "r+");

        if(fp == NULL){
                perror("showlddr");
                exit(EXIT_FAILURE);
        }

        number = valid_records (fp);

        them = (player *)malloc((sizeof(player) * number));

        if(them == NULL){
                fprintf(stderr,"showlddr: out of memory\n");
                exit(EXIT_FAILURE);
        }

        if(read_records(fp, number, them) != number){
                fprintf(stderr, "showlddr: error while reading"
                                        " player records\n");
                free(them);
                fclose(fp);
                exit(EXIT_FAILURE);
        }

        fclose(fp);

        sort_players(them, number);

        if(print_records(them, number) != number){
                fprintf(stderr, "showlddr: error while printing"
                                        " player records\n");
                free(them);
                exit(EXIT_FAILURE);
        }

        free(them);
        exit(EXIT_SUCCESS);
}