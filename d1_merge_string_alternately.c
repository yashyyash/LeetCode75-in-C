#include <stdio.h>
#include <stdlib.h> // For malloc and free
#include <string.h> // For strlen

// Function to merge two strings alternately
char* mergeAlternately(const char* word1, const char* word2) {
    int len1 = strlen(word1); // Length of the first string
    int len2 = strlen(word2); // Length of the second string
    int totalLen = len1 + len2; // Total length of the merged string
    
    // Allocate memory for the merged string plus the null terminator
    char* mergedString = (char*)malloc((totalLen + 1) * sizeof(char));
    
    if (mergedString == NULL) { // Check if memory allocation was successful
        return NULL;
    }

    int i = 0; // Index for word1
    int j = 0; // Index for word2
    int k = 0; // Index for mergedString

    // Merge strings alternately
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

int main() {
    const char word1[] = "abcd"; // First string
    const char word2[] = "pq";   // Second string

    char* result = mergeAlternately(word1, word2); // Merge the strings
    if (result != NULL) { // Check if merging was successful
        printf("Merged String: %s\n", result);
        free(result); // Free the allocated memory
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
