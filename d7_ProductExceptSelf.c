#include <stdlib.h>

# /**
#  * Note: The returned array must be malloced, assume caller calls free().
#  */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    // Allocate memory for the result array
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    
    // Initialize the first element of the result as 1
    result[0] = 1;
    
    // Calculate the product of all elements to the left of each element
    for (int i = 1; i < numsSize; i++) {
        result[i] = result[i - 1] * nums[i - 1];
    }
    
    // Initialize a variable to keep track of the product of elements to the right
    int rightProduct = 1;
    
    // Calculate the product of all elements to the right of each element
    for (int i = numsSize - 1; i >= 0; i--) {
        result[i] *= rightProduct;
        rightProduct *= nums[i];
    }
    
    return result;
}
