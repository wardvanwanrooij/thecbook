/*
*
* Declarations and definitions for functions which manipulate player
* records which form the basis of the ladder
*
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NAMELEN 12              /* max. for player name length */

#define LENBUF 256              /* max. for input buffer length */

#define CHALLENGE_RANGE 3       /* number of higher ranked players who may
                                * be challenged to move up in rank
                                */

extern char *OptArg;

typedef struct {
        char    name[NAMELEN+1];
        int     rank;
        int     wins;
        int     losses;
        time_t  last_game;
} player;

#define NULLPLAYER (player *)0

extern const char *LadderFile;

extern const char *WrFmt;       /* used when writing records */
extern const char *RdFmt;       /* used when reading records */

/*
* Declarations for routines used to manipulate the player records
* and the ladder file which are defined in player.c
*
*/

int     valid_records(FILE *);
int     read_records(FILE *, int, player *);
int     write_records(FILE *, player *, int);
player *find_by_name(char *, player *, int);
player *find_by_rank(int, player *, int);
void    push_down(player *, int, int, int);
int     print_records(player *, int);
void    copy_player(player *, player *);
int     compare_name(player *, player *);
int     compare_rank(player *, player *);
void    sort_players(player *, int);