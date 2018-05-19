/*
 * Filename:    main.c
 * Author:      Brendan Thompson
 * Description: Driver for codenames program
 * Date:        May 19 2018
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "codenames.h"

long main( int argc, char *argv[] ) {

  long seed;
  char team;

  char *endptr;

  char *( *words )[NUM_CELLS] = NULL;
  char *( *colors )[NUM_CELLS] = NULL;

  // too many args
  if( argc > MAX_ARGS ) {
    fprintf( stderr, STR_USAGE, argv[0] );
    return EXIT_FAILURE;
  }

  // check seed
  if( argc >= SEED_INDEX + 1 ) {
    // reset errno
    errno = 0;
    seed = strtol( argv[SEED_INDEX], &endptr, 10 );

    // if an error occured...
    if( !errno || *endptr != '\0' ) {
      fprintf( stderr, STR_USAGE, argv[0] );
      return EXIT_FAILURE;
    }    
  }
  else seed = rand();

  // check team
  if( argc >= TEAM_INDEX + 1 ) {
    if( strlen( argv[TEAM_INDEX] ) != 1 ) {
      fprintf( stderr, STR_USAGE, argv[0] );
      return EXIT_FAILURE;
    }

    team = *argv[TEAM_INDEX];

    if( team != CHAR_RED && team != CHAR_BLUE && team != CHAR_WILD ) {
      fprintf( stderr, STR_USAGE, argv[0] );
      return EXIT_FAILURE;
    }
  }
  else team = CHAR_WILD;

  srand( seed );

  words = wordGen();
  colors = colorGen( team );

  for( int i = 0; i < NUM_CELLS; i++ ) {
    printf( STR_GRID_CELL, (*colors)[i], (*words)[i] );
    if( i % GRID_SIZE == 0 ) printf( "\n" );
  }

  return EXIT_SUCCESS;
}
