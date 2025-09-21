#ifndef MYFILEFUNCTIONS_H
#define MYFILEFUNCTIONS_H

#include <stdio.h>  // for FILE*

// Count the number of lines, words, and characters in the given file
// Returns 0 on success, -1 on failure
int wordCount(FILE* file, int* lines, int* words, int* chars);

// Search lines containing search_str in a file
// Fills the matches array, returns number of matches, -1 on failure
int mygrep(FILE* fp, const char* search_str, char*** matches);

#endif
