#include <stdio.h>
#include <string.h>

char* removeStars(char* s) {
    int n = strlen(s);
    int index = 0; // This will keep track of the position in the resulting string

    // Create a dynamic array to store the resulting string
    char* result = (char*)malloc((n + 1) * sizeof(char));

    // Iterate through the string
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            // If we encounter a star, we "remove" the last added character by decrementing the index
            if (index > 0) {
                index--;
            }
        } else {
            // Otherwise, we add the character to the result and move the index forward
            result[index++] = s[i];
        }
    }

    // Null-terminate the result string
    result[index] = '\0';
    return result;
}
