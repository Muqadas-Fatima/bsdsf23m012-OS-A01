#include "../include/mystrfunctions.h"
#include <stdio.h>

//  len of a str
int mystrlen(const char* s) {
    int length = 0;
    
    while (s[length] != '\0') {
        length++;
    }
    return length;
}

// Copy source to des str
int mystrcpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];    
        i++;
    }
    dest[i] = '\0'; 
    return i; }

// copy  n chara from source to dest
int mystrncpy(char* dest, const char* src, int n) {
    int i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    // source was shorter than n, add null terminator
    if (i < n) {
        dest[i] = '\0';
    }
    return i; 
}

// Concatenate source str to the end of dest
int mystrcat(char* dest, const char* src) {
    int dest_len = mystrlen(dest);     int i = 0;
    while (src[i] != '\0') {
        dest[dest_len + i] = src[i]; 
        i++;
    }
    dest[dest_len + i] = '\0'; 
    return dest_len + i; 
}
