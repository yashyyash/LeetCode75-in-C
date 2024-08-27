#include <stdio.h>

double findMaxAverage(int* nums, int numsSize, int k) {
    // Calculate the sum of the first k elements
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += nums[i];
    }
    
    // Initialize maxSum to the sum of the first k elements
    int maxSum = sum;
    
    // Slide the window across the array
    for (int i = k; i < numsSize; i++) {
        sum += nums[i] - nums[i - k];
        if (sum > maxSum) {
            maxSum = sum;
        }
    }
    
    // Return the maximum average value
    return (double)maxSum / k;
}