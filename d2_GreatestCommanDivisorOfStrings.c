#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to find the greatest common divisor of str1 and str2
char* gcdOfStrings(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Function to compute the GCD of the two numbers
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Function to check if string "s" can be formed by repeating string 't'
    int isDivisible(char *s, char *t) {
        int s_len = strlen(s);
        int t_len = strlen(t);

        // If s_len is not a multiple of t_len, return 0 (false)
        if (s_len % t_len != 0) return 0;

        // Check if repeating "t" can recreate 's'
        for (int i = 0; i < s_len; i++) {
            if (s[i] != t[i % t_len]) return 0;
        }
        return 1; // Return 1 (true) if "s" can be formed by repeating 't'
    }

    // Calculate the GCD of the lengths
    int gcd_len = gcd(len1, len2);

    // Extract the potential common divisor string from `str1`
    char candidate[gcd_len + 1];
    strncpy(candidate, str1, gcd_len);
    candidate[gcd_len] = '\0';  // Null-terminate the string

    // Check if the candidate string can divide both `str1` and `str2`
    if (isDivisible(str1, candidate) && isDivisible(str2, candidate)) {
        // Allocate memory for the result and copy the candidate
        char *result = (char*)malloc((gcd_len + 1) * sizeof(char));
        if (result != NULL) {
            strcpy(result, candidate);
            return result; // Return the candidate if it works for both
        } else {
            return NULL; // Memory allocation failed
        }
    } else {
        // Allocate memory for an empty string
        char *result = (char*)malloc(1 * sizeof(char));
        if (result != NULL) {
            result[0] = '\0'; // Return an empty string if no common divisor is found
            return result;
        } else {
            return NULL; // Memory allocation failed
        }
    }
}


