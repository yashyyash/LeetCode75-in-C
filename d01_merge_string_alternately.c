#include <stdio.h>
#include <stdlib.h> // For malloc and free
#include <string.h> // For strlen

// Function to merge two strings alternately
char* mergeAlternately(const char* word1, const char* word2) {
    int len1 = strlen(word1); // Get the length of the first string
    int len2 = strlen(word2); // Get the length of the second string
    int totalLen = len1 + len2; // Calculate the total length of the merged string
    
    // Allocate memory for the merged string plus the null terminator
    char* mergedString = (char*)malloc((totalLen + 1) * sizeof(char));
    
    if (mergedString == NULL) { // Check if memory allocation was successful
        return NULL;
    }

    int i = 0; // Index for iterating through word1
    int j = 0; // Index for iterating through word2
    int k = 0; // Index for building mergedString

    // Merge the strings alternately
    while (i < len1 || j < len2) {
        if (i < len1) { // Add character from word1 if available
            mergedString[k++] = word1[i++];
        }
        if (j < len2) { // Add character from word2 if available
            mergedString[k++] = word2[j++];
        }
    }

    // Null-terminate the merged string
    mergedString[k] = '\0';

    return mergedString;
}
