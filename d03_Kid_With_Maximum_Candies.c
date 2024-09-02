/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 #include <stdbool.h>
 #include <stdlib.h>

bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    // step 1: finding the maximum number of candies any kid has    
    int maxCandies = 0;
    for(int i = 0; i <  candiesSize; i++){
        if (candies[i] > maxCandies){
            maxCandies = candies[i];
        }
    }

    // Step 2: Allocating Memory 
    bool* result = (bool*)malloc(candiesSize * sizeof(bool));

    //step 3: Check if each kid can have the most candies
    for (int i = 0; i < candiesSize; i++){
        result[i] = (candies[i] + extraCandies) >= maxCandies;
    }

    //step 4 : set the retuen size
    *returnSize = candiesSize;

    return result;
}