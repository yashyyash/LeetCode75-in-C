#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if a character is a vowel
bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int maxVowels(char *s, int k) {
    int max_vowels = 0, current_vowels = 0;
    int n = strlen(s);

    // Initialize the first window of size k
    for (int i = 0; i < k; i++) {
        if (isVowel(s[i])) {
            current_vowels++;
        }
    }

    max_vowels = current_vowels;

    // Slide the window over the string
    for (int i = k; i < n; i++) {
        // Add the new character to the window
        if (isVowel(s[i])) {
            current_vowels++;
        }

        // Remove the old character from the window
        if (isVowel(s[i - k])) {
            current_vowels--;
        }

        // Update max_vowels if the current window has more vowels
        if (current_vowels > max_vowels) {
            max_vowels = current_vowels;
        }
    }

    return max_vowels;
}

int main() {
    char s[] = "abciiidef";
    int k = 3;
    int result = maxVowels(s, k);
    printf("Maximum number of vowels in any substring of length %d is: %d\n", k, result);
    return 0;
}
