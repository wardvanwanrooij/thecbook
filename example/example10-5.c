/*
* Generic functions to manipulate the ladder data file and
* player records.
*
*/

#include "player.h"

const char *LadderFile = "ladder";

const char *WrFmt = "%s %d      %d      %d      %ld\n";
const char *RdFmt = "%s %d      %d      %d      %ld";


/* note use of string-joining */
const char *HeaderLine =
        "Player Rank Won Lost Last Game\n"
        "===============================================\n";

const char *PrtFmt = "%-12s%4d %4d %4d %s\n";

/* return the number of records in the data file */

int valid_records(FILE *fp)
{
        int i = 0;
        long plrs = 0L;
        long tmp = ftell(fp);
        char buf[LENBUF];

        fseek(fp, 0L, SEEK_SET);

        for(i = 0; fgets(buf, LENBUF, fp) != NULL ; i++)
                ;

        /* Restore the file pointer to original state */

        fseek(fp, tmp, SEEK_SET);

        return i;
}

/* read num player records from fp into the array them */

int read_records(FILE *fp, int num, player *them)
{
        int i = 0;
        long tmp = ftell(fp);

        if(num == 0)
                return 0;

        fseek(fp, 0L, SEEK_SET);

        for(i = 0 ; i < num ; i++){
                if(fscanf(fp, RdFmt, (them[i]).name,
                                &((them[i]).rank),
                                &((them[i]).wins),
                                &((them[i]).losses),
                                &((them[i]).last_game)) != 5)
                        break;          /* error on fscanf! */
        }

        fseek(fp, tmp, SEEK_SET);
        return i;
}

/* write num player records to the file fp from the array them */

int write_records(FILE *fp, player *them, int num)
{
        int i = 0;

        fseek(fp, 0L, SEEK_SET);

        for(i = 0 ; i < num ; i++){
                if(fprintf(fp, WrFmt, (them[i]).name,
                                (them[i]).rank,
                                (them[i]).wins,
                                (them[i]).losses,
                                (them[i]).last_game) < 0)
                        break;          /* error on fprintf! */
        }

        return i;
}

/*
* return a pointer to the player in array them
* whose name matches name
*/

player *find_by_name(char * name, player *them, int num)
{
        player *pp = them;
        int i = 0;

        for(i = 0; i < num; i++, pp++)
                if(strcmp(name, pp->name) == 0)
                        return pp;

        return NULLPLAYER;
}

/*
* return a pointer to the player in array them
* whose rank matches rank
*/

player *find_by_rank(int rank, player *them, int num)
{
        player *pp = them;
        int i = 0;

        for(i = 0; i < num; i++, pp++)
                if(rank == pp->rank)
                        return pp;

        return NULLPLAYER;
}

/*
* reduce by one the ranking of all players in array them
* whose ranks are now between start and end
*/

void push_down(player *them, int number, int start, int end)
{
        int i;
        player *pp;

        for(i = end; i >= start; i--){
        if((pp = find_by_rank(i, them, number)) == NULLPLAYER){
                fprintf(stderr,
                        "error: could not find player ranked %d\n", i);
                free(them);
                exit(EXIT_FAILURE);
        } else
                (pp->rank)++;
        }
}

/* pretty print num player records from the array them */

int print_records(player *them, int num)
{
        int i = 0;

        printf(HeaderLine);

        for(i = 0 ; i < num ; i++){
                if(printf(PrtFmt,
                        (them[i]).name, (them[i]).rank,
                        (them[i]).wins, (them[i]).losses,
                        asctime(localtime(&(them[i]).last_game))) < 0)
                        break;          /* error on printf! */
        }

        return i;
}

/* copy the values from player from to player to */

void copy_player(player *to, player *from)
{
        if((to == NULLPLAYER) || (from == NULLPLAYER))
                return;

        *to = *from;
        return;
}

/* compare the names of player first and player second */

int compare_name(player *first, player *second)
{
        return strcmp(first->name, second->name);
}

/* compare the ranks of player first and player second */

int compare_rank(player *first, player *second)
{
        return (first->rank - second->rank);
}

/* sort num player records in the array them */

void sort_players(player *them, int num)
{
        qsort(them, num, sizeof(player), compare_rank);
}