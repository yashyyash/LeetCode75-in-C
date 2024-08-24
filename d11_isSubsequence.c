#include <stdbool.h>

bool isSubsequence(char* s, char* t) {
    int i = 0;  // Pointer for string 's'
    int j = 0;  // Pointer for string 't'

    // Iterate through 't'
    while (t[j] != '\0') {
        if (s[i] == t[j]) {
            i++;  // Move pointer 'i' if characters match
        }
        j++;  // Always move pointer 'j'
    }

    // If we've checked all characters in 's', return true
    return s[i] == '\0';
}
