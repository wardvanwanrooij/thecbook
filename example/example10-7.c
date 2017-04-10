/*
* Program to add a new player to the ladder.
* You are expected to assign a realistic
* ranking value to the player.
*
*/

#include "player.h"

const char *ValidOpts = "n:r:f:";

char *OtherFile;

static const char *Usage = "usage: newplyr -r rank -n name [-f file]\n";

/* Forward declaration of function defined in this file */

void record(player *extra);

int main(int argc, char *argv[])
{
        char ch;
        player dummy, *new = &dummy;

        if(argc < 5){
                fprintf(stderr, Usage);
                exit(EXIT_FAILURE);
        }

        while((ch = options(argc, argv, ValidOpts)) != -1){
                switch(ch){
                case 'f':
                        OtherFile=OptArg;
                        break;
                case 'n':
                        strncpy(new->name, OptArg, NAMELEN);
                        new->name[NAMELEN] = 0;
                        if(strcmp(new->name, OptArg) != 0)
                                fprintf(stderr,
                                        "Warning: name truncated to %s\n", new->name);
                        break;
                case 'r':
                        if((new->rank = atoi(OptArg)) == 0){
                                fprintf(stderr, Usage);
                        exit(EXIT_FAILURE);
                        }
                        break;
                case '?':
                        fprintf(stderr, Usage);
                        break;
                }
        }

        if((new->rank == 0)){
                fprintf(stderr, "newplyr: bad value for rank\n");
                exit(EXIT_FAILURE);
        }

        if(strlen(new->name) == 0){
                fprintf(stderr,
                        "newplyr: needs a valid name for new player\n");
                exit(EXIT_FAILURE);
        }

        new->wins = new->losses = 0;
        time(& new->last_game); /* make now the time of the "last game" */

        record(new);

        exit(EXIT_SUCCESS);
}

void record(player *extra)
{
        int number, new_number, i;
        player *them;
        const char *fname =(OtherFile==0)?LadderFile:OtherFile;
        FILE *fp;

        fp = fopen(fname, "r+");

        if(fp == NULL){
                if((fp = fopen(fname, "w")) == NULL){
                        perror("newplyr");
                        exit(EXIT_FAILURE);
                }
        }

        number = valid_records (fp);
        new_number = number + 1;

        if((extra->rank <= 0) || (extra->rank > new_number)){
                fprintf(stderr,
                        "newplyr: rank must be between 1 and %d\n",
                        new_number);
                exit(EXIT_FAILURE);
        }

        them = (player *)malloc((sizeof(player) * new_number));

        if(them == NULL){
                fprintf(stderr,"newplyr: out of memory\n");
                exit(EXIT_FAILURE);
        }

        if(read_records(fp, number, them) != number){
                fprintf(stderr,
                        "newplyr: error while reading player records\n");
                free(them);
                exit(EXIT_FAILURE);
        }

        if(find_by_name(extra->name, them, number) != NULLPLAYER){
                fprintf(stderr,
                        "newplyr: %s is already on the ladder\n",
                        extra->name);
                free(them);
                exit(EXIT_FAILURE);
        }

        copy_player(&them[number], extra);

        if(extra->rank != new_number)
                push_down(them, number, extra->rank, number);

        sort_players(them, new_number);

        if((fp = freopen(fname, "w+", fp)) == NULL){
                perror("newplyr");
                free(them);
                exit(EXIT_FAILURE);
        }

        if(write_records(fp, them, new_number) != new_number){
                fprintf(stderr,
                        "newplyr: error while writing player records\n");
                fclose(fp);
                free(them);
                exit(EXIT_FAILURE);
        }
        fclose(fp);
        free(them);
}