/*
 * Filename:    wordGen.c
 * Author:      Brendan Thompson
 * Userid:      cs30xpm
 * Description: Generates a 5x5 grid of words
 * Date:        May 19 2018
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "codenames.h"

void wordGen( char *( *wordsPtr)[] ) {

  int i;

  FILE *file;
  long numWords;

  char *tmp;

  char wordList[MAX_WORDS][MAX_WORD_LEN + 1];

  errno = 0;
  file = fopen( FILE_PATH, "r" );

  numWords = 0;

  // creates array of all possible words
  while( fgets( wordList[numWords], MAX_WORD_LEN, file ) != NULL ) {
    tmp = strchr( wordList[numWords], '\r' );
    if( tmp ) *tmp = ' ';

    tmp = strchr( wordList[numWords], '\n' );
    if( tmp ) *tmp = ' ';

    for( i = strlen( wordList[numWords] ); i < MAX_WORD_LEN - 1; i++ ) {
      wordList[numWords][i] = ' ';
    }

    numWords++;
  }

  // we done with this shit
  fclose( file );

  // pick 25 distinct random words for the grid
  for( i = 0; i < NUM_CELLS; i++ ) {
    // make sure the word is unique
    do {
      tmp = wordList[ rand() % numWords ];
    } while(*tmp == '\0');

    // allocate and copy 
    (*wordsPtr)[i] = calloc( MAX_WORD_LEN, 1 );
    strncpy( (*wordsPtr)[i], tmp, MAX_WORD_LEN );
    *tmp = '\0';
  }
}
