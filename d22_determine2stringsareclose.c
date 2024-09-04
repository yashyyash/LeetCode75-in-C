#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// Helper function for sorting
int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

bool closeStrings(char *word1, char *word2) {
    // If lengths are different, they cannot be close
    if (strlen(word1) != strlen(word2)) {
        return false;
    }
    
    int freq1[26] = {0};
    int freq2[26] = {0};
    int unique1[26] = {0};
    int unique2[26] = {0};
    
    // Count the frequency of each character in word1 and word2
    for (int i = 0; word1[i]; ++i) {
        freq1[word1[i] - 'a']++;
        freq2[word2[i] - 'a']++;
        unique1[word1[i] - 'a'] = 1;
        unique2[word2[i] - 'a'] = 1;
    }
    
    // Check if both words have the same unique characters
    for (int i = 0; i < 26; ++i) {
        if (unique1[i] != unique2[i]) {
            return false;
        }
    }
    
    // Sort the frequency arrays
    int freq1_sorted[26], freq2_sorted[26];
    memcpy(freq1_sorted, freq1, sizeof(freq1));
    memcpy(freq2_sorted, freq2, sizeof(freq2));
    
    // Sort frequencies
    qsort(freq1_sorted, 26, sizeof(int), cmpfunc);
    qsort(freq2_sorted, 26, sizeof(int), cmpfunc);
    
    // Check if both words have the same frequency counts
    for (int i = 0; i < 26; ++i) {
        if (freq1_sorted[i] != freq2_sorted[i]) {
            return false;
        }
    }
    
    return true;
}
