/*
 * Filename:    colorGen.c
 * Author:      Brendan Thompson
 * Description: Generates color codes for grid
 * Date:        May 19 2018
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "codenames.h"

void colorGen( char *( *colorsPtr )[], char team ) {

  char *team1color;
  char *team2color;

  int teamIds[NUM_CELLS] = {BLANK_ID};
  int i, tmp;

  // if wildcard pick random team1
  if( team == CHAR_WILD ) {
    team = rand() % 2 == 0 ? CHAR_RED : CHAR_BLUE;
  }

  // if red is team1
  if( team == CHAR_RED ) {
    team1color = C_RED;
    team2color = C_BLU;
    printf( "Red is going first\n" );
  }
  // if blue is team1
  else {
    printf( "Blue is going first\n" );
    team1color = C_BLU;
    team2color = C_RED;
  }


  // pick black cell
  teamIds[rand() % (NUM_CELLS)] = BLACK_ID;

  // pick cells for team 1
  for( i = 0; i < TEAM_1_SIZE; i++ ) {
    do {
      tmp = rand() % (NUM_CELLS);
    } while( teamIds[tmp] != 0 );

    teamIds[tmp] = TEAM_1_ID;
  }

  // pick cells for team 2
  for( i = 0; i < TEAM_2_SIZE; i++ ) {
    do {
      tmp = rand() % (NUM_CELLS);
    } while( teamIds[tmp] != BLANK_ID );

    teamIds[tmp] = TEAM_2_ID;
  }

  // set colors for all of the cells
  for( i = 0; i < NUM_CELLS; i++ ) {
    (*colorsPtr)[i] = calloc( C_BUFFER, 1 );

    if( teamIds[i] == BLANK_ID ) 
      strncpy( (*colorsPtr)[i], C_WHT, strlen( C_WHT ) + 1 );
    else if( teamIds[i] == BLACK_ID ) 
      strncpy( (*colorsPtr)[i], C_YEL, strlen( C_YEL ) + 1 );
    else if( teamIds[i] == TEAM_1_ID ) 
      strncpy( (*colorsPtr)[i], team1color, strlen( team1color ) + 1 );
    else if( teamIds[i] == TEAM_2_ID ) 
      strncpy( (*colorsPtr)[i], team2color, strlen( team2color ) + 1 );
  }
}
