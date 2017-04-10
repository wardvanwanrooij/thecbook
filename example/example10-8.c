/*
* Program to record a result in the ladder
*
*/

#include "player.h"

/* Forward declarations for functions defined in this file */

char *read_name(char *, char *);
void move_winner(player *, player *, player *, int);

const char *ValidOpts = "f:";

const char *Usage = "usage: result [-f file]\n";

char *OtherFile;

int main(int argc, char *argv[])
{
        player *winner, *loser, *them;
        int number;
        FILE *fp;
        const char *fname;
        char buf[LENBUF], ch;

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
                perror("result");
                exit(EXIT_FAILURE);
        }

        number = valid_records (fp);

        them = (player *)malloc((sizeof(player) * number));

        if(them == NULL){
                fprintf(stderr,"result: out of memory\n");
                exit(EXIT_FAILURE);
        }

        if(read_records(fp, number, them) != number){
                fprintf(stderr,
                        "result: error while reading player records\n");
                fclose(fp);
                free(them);
                exit(EXIT_FAILURE);
        }

        fclose(fp);

        if((winner = find_by_name(read_name(buf, "winner"), them, number))
                == NULLPLAYER){
                fprintf(stderr,"result: no such player %s\n",buf);
                free(them);
                exit(EXIT_FAILURE);
        }

        if((loser = find_by_name(read_name(buf, "loser"), them, number))
                == NULLPLAYER){
                fprintf(stderr,"result: no such player %s\n",buf);
                free(them);
                exit(EXIT_FAILURE);
        }

        winner->wins++;
        loser->losses++;

        winner->last_game = loser->last_game = time(0);

        if(loser->rank < winner->rank)
                if((winner->rank - loser->rank) <= CHALLENGE_RANGE)
                        move_winner(winner, loser, them, number);

        if((fp = freopen(fname, "w+", fp)) == NULL){
                perror("result");
                free(them);
                exit(EXIT_FAILURE);
        }

        if(write_records(fp, them, number) != number){
                fprintf(stderr,"result: error while writing player records\n");
                free(them);
                exit(EXIT_FAILURE);
        }
        fclose(fp);
        free(them);
        exit(EXIT_SUCCESS);
}

void move_winner(player *ww, player *ll, player *them, int number)
{
        int loser_rank = ll->rank;

        if((ll->rank - ww->rank) > 3)
                return;

        push_down(them, number, ll->rank, (ww->rank - 1));
        ww->rank = loser_rank;
        sort_players(them, number);
        return;
}

char *read_name(char *buf, char *whom)
{
        for(;;){
                char *cp;
                printf("Enter name of %s : ",whom);
                if(fgets(buf, LENBUF, stdin) == NULL)
                        continue;
                /* delete newline */
                cp = &buf[strlen(buf)-1];
                if(*cp == '\n')
                        *cp = 0;
                /* at least one char? */
                if(cp != buf)
                        return buf;
        }
}