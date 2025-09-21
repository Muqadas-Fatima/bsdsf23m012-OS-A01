#include "../include/myfilefunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wordCount(FILE* file, int* lines, int* words, int* chars) {
    if (!file) return -1;
    *lines = *words = *chars = 0;
    char c, prev = '\0';
    while ((c = fgetc(file)) != EOF) {
        (*chars)++;
        if (c == '\n') (*lines)++;
        if ((c==' ' || c=='\n' || c=='\t') && (prev!=' ' && prev!='\n' && prev!='\t')) (*words)++;
        prev = c;
    }
    if(prev != ' ' && prev != '\n' && prev != '\t') (*words)++;
    rewind(file);
    return 0;
}

int mygrep(FILE* fp, const char* search_str, char*** matches) {
    if(!fp || !search_str) return -1;
    char line[1024];
    int count=0, size=10;
    *matches = malloc(size * sizeof(char*));
    while(fgets(line, sizeof(line), fp)) {
        if(strstr(line, search_str)) {
            if(count >= size) {
                size *= 2;
                *matches = realloc(*matches, size * sizeof(char*));
            }
            (*matches)[count] = strdup(line);
            count++;
        }
    }
    rewind(fp);
    return count;
}
