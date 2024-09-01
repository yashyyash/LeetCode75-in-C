#include <stdio.h>

// Function to find the pivot index
int pivotIndex(int* nums, int numsSize) {
    int totalSum = 0, leftSum = 0;
    
    // Calculate the total sum of the array
    for (int i = 0; i < numsSize; i++) {
        totalSum += nums[i];
    }
    
    // Iterate through the array to find the pivot index
    for (int i = 0; i < numsSize; i++) {
        if (leftSum == (totalSum - leftSum - nums[i])) {
            return i; // Return the pivot index
        }
        leftSum += nums[i];
    }
    
    return -1; // Return -1 if no pivot index is found
}

// int main() {
//     int nums[] = {1, 7, 3, 6, 5, 6}; // Example input
//     int numsSize = sizeof(nums) / sizeof(nums[0]);
    
//     int pivot = pivotIndex(nums, numsSize);
    
//     if (pivot != -1) {
//         printf("Pivot index: %d\n", pivot);
//     } else {
//         printf("No pivot index found\n");
//     }

//     return 0;
// }
