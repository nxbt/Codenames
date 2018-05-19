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

char *( *wordGen() )[] {

  FILE *file;
  char *words[NUM_CELLS];
  long numWords;

  char *( *wordsPtr )[NUM_CELLS] = &words;

  char *tmp;

  char wordList[MAX_WORDS][MAX_WORD_LEN];

  errno = 0;
  file = fopen( FILE_PATH, "r" );

  numWords = 0;

  // creates array of all possible words
  while( fgets( wordList[numWords], MAX_WORD_LEN, file ) != NULL ) {
//    *strchr( wordList[numWords], '\n' ) = '\0';
    numWords++;
  }

  // we done with this shit
  fclose( file );

  // pick 25 distinct random words for the grid
  for( int i = 0; i < NUM_CELLS; i++ ) {
    // make sure the word is unique
    do {
      tmp = wordList[ rand() % numWords ];
    } while(*tmp == '\0');

    // allocate and copy 
    words[i] = calloc( strlen( tmp ) + 1, 1 );
    strncpy( words[i], tmp, strlen( tmp ) + 1 );
    *tmp = '\0';
  }

  return wordsPtr;
}
