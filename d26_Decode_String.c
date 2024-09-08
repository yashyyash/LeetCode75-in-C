#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Helper function to repeat a string `k` times
char* repeatString(const char* str, int k) {
    int len = strlen(str);
    char* result = (char*)malloc(k * len + 1);  // Allocate memory for the repeated string
    result[0] = '\0';  // Initialize the result string
    
    for (int i = 0; i < k; i++) {
        strcat(result, str);  // Append the string `k` times
    }
    
    return result;
}

// Safe append function that reallocates memory if needed
void safeAppend(char** dest, const char* src) {
    size_t newLength = strlen(*dest) + strlen(src) + 1;  // New length needed
    *dest = realloc(*dest, newLength);  // Reallocate memory for the destination
    strcat(*dest, src);  // Append the source string to the destination
}

// Main function to decode the string
char* decodeString(char* s) {
    int len = strlen(s);
    char* stack[1000];  // Stack to store intermediate results
    int repeatStack[1000];  // Stack to store repetition counts
    int top = -1, repeatTop = -1;  // Stack pointers
    
    char* current = (char*)malloc(1);  // Current decoded substring buffer
    current[0] = '\0';  // Initialize current string
    
    int repeat = 0;  // Current repeat count
    
    for (int i = 0; i < len; i++) {
        if (isdigit(s[i])) {
            // If it's a digit, accumulate the repeat count
            repeat = repeat * 10 + (s[i] - '0');
        } else if (s[i] == '[') {
            // Push current string and repeat count onto the stack
            stack[++top] = strdup(current);  // Store the current string
            repeatStack[++repeatTop] = repeat;  // Store the repeat count
            
            // Reset current string and repeat count for the next part
            free(current);
            current = (char*)malloc(1);
            current[0] = '\0';
            repeat = 0;
        } else if (s[i] == ']') {
            // Pop the repeat count from the stack
            int k = repeatStack[repeatTop--];
            
            // Create the repeated substring
            char* repeatedStr = repeatString(current, k);
            
            // Pop the previous substring from the stack and append the repeated string
            char* previous = stack[top--];  // Previous string from the stack
            safeAppend(&previous, repeatedStr);  // Append repeated string to previous
            free(current);
            current = previous;  // Update current string
            
            // Free the temporary repeated string
            free(repeatedStr);
        } else {
            // It's a letter, so append it to the current string
            char temp[2] = {s[i], '\0'};  // Convert char to string
            safeAppend(&current, temp);  // Append it to current
        }
    }
    
    // The final decoded string is in `current`
    return current;
}
