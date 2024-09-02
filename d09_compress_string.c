int compress(char* chars, int charsSize) {
    int write = 0; // Pointer to write the compressed result
    int i = 0;     // Pointer to read through the input array
    
    while (i < charsSize) {
        char currentChar = chars[i];
        int count = 0;
        
        // Count the number of consecutive repeating characters
        while (i < charsSize && chars[i] == currentChar) {
            i++;
            count++;
        }
        
        // Write the character
        chars[write++] = currentChar;
        
        // If the count is more than 1, write the count digits
        if (count > 1) {
            char countStr[10];
            int countLen = sprintf(countStr, "%d", count);
            for (int j = 0; j < countLen; j++) {
                chars[write++] = countStr[j];
            }
        }
    }
    
    return write; // Return the new length of the compressed array
}
