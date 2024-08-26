#include <stdio.h>
#include <stdlib.h>

int compare(const int *a, const int *b);

int maxOperations(int* nums, int numsSize, int k) {
    int maxOperations = 0;
    
    // Sort the array to apply two-pointer technique
    qsort(nums, numsSize, sizeof(int), (int (*)(const void *, const void *)) compare);
    
    int left = 0;
    int right = numsSize - 1;
    
    while (left < right) {
        int sum = nums[left] + nums[right];
        
        if (sum == k) {
            maxOperations++;
            left++;
            right--;
        } else if (sum < k) {
            left++;
        } else {
            right--;
        }
    }
    
    return maxOperations;
}

int compare(const int *a, const int *b) {
    return (*a - *b);
}
