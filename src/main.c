#include <stdio.h>
#include <stdlib.h> // for malloc and free
#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main() {
    
    printf("--- Testing String Functions ---\n");

    char str1[100] = "Hello";
    char str2[100] = "World";

    // print the leng of str1
    int len = mystrlen(str1);
    printf("Length of '%s' = %d\n", str1, len);

    // concat str2 to str1
    mystrcat(str1, str2);
    printf("After concatenation: %s\n", str1);

    //Testing File Functions 
    printf("\n--- Testing File Functions ---\n");

    FILE *fp = fopen("sample.txt", "r"); // Open sample.txt for reading
    if (fp == NULL) {
        printf("sample.txt not found!\n");
        return 1; // exit if file not found
    }
    int lines = 0, words = 0, chars = 0;
    wordCount(fp, &lines, &words, &chars);
    printf("Lines: %d, Words: %d, Chars: %d\n", lines, words, chars);
    char **matches = NULL;
    int found = mygrep(fp, "test", &matches);
    printf("Found %d matching lines\n", found);

    // Free allocated memory in heap
    for (int i = 0; i < found; i++) {
        free(matches[i]);
    }
    free(matches);

    fclose(fp); // Close the file
    return 0;
}
