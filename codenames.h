/*
 * Filename:    wordGen.h
 * Author:      Brendan Thompson
 * Description: Constants and function prototypes
 * Date:        May 19 2018
 */

#define GRID_SIZE 5
#define NUM_CELLS GRID_SIZE * GRID_SIZE

#define MAX_ARGS 3

#define TEAM_INDEX 1
#define SEED_INDEX 2

#define CHAR_RED 'r'
#define CHAR_BLUE 'b'
#define CHAR_WILD 'x'

#define MAX_WORDS 2000
#define MAX_WORD_LEN 21

#define TEAM_1_SIZE 9
#define TEAM_2_SIZE 8

#define BLANK_ID 0
#define TEAM_1_ID 1
#define TEAM_2_ID 2
#define BLACK_ID 3

#define C_BUFFER 8

#define clear() printf("\033[H\033[J")

#define FILE_PATH "./codenames.data"

#define STR_GRID_CELL "%s%s"
#define STR_USAGE "USAGE: %s [r/b/x] [seed]\n"\
                  "  Where [r/b/x] is what team goes first\n"\
                  "  Where [seed] is a long for random generation\n\n"

#define C_NRM  "\x1B[0m"
#define C_BLK  "\x1B[30m"
#define C_RED  "\x1B[31m"
#define C_GRN  "\x1B[32m"
#define C_YEL  "\x1B[33m"
#define C_BLU  "\x1B[34m"
#define C_MAG  "\x1B[35m"
#define C_CYN  "\x1B[36m"
#define C_WHT  "\x1B[37m"

#define B_BLK  "\x1B[40m"

/* Function Prototypes */
void wordGen( char *( *wordPtr )[] );
void colorGen( char *( *colorsPtr )[], char team );
