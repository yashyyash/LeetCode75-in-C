#include <stdio.h>

int longestSubarray(int* nums, int numsSize) {
    int left = 0, right = 0;    // Two pointers
    int maxLen = 0;             // To store the maximum length of subarray
    int zeroCount = 0;          // To count the number of zeros in the window
    
    // Traverse through the array
    while (right < numsSize) {
        if (nums[right] == 0) {
            zeroCount++;
        }
        
        // If more than 1 zero in the current window, shrink the window
        while (zeroCount > 1) {
            if (nums[left] == 0) {
                zeroCount--;
            }
            left++;
        }
        
        // Calculate the maximum length
        maxLen = maxLen > (right - left) ? maxLen : (right - left);
        right++;
    }
    
    // Return the maximum length
    return maxLen;
}

// int main() {
//     int nums[] = {1, 1, 0, 1};
//     int numsSize = sizeof(nums) / sizeof(nums[0]);
    
//     int result = longestSubarray(nums, numsSize);
//     printf("The size of the longest subarray is: %d\n", result);
    
//     return 0;
// }
