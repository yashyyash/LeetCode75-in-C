#include <string.h>
#include <ctype.h>

bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

char* reverseVowels(char* s) {
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {
        // Move the left pointer until a vowel is found
        while (left < right && !isVowel(s[left])) {
            left++;
        }
        // Move the right pointer until a vowel is found
        while (left < right && !isVowel(s[right])) {
            right--;
        }

        // Swap the vowels
        if (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
    
    return s;
}
