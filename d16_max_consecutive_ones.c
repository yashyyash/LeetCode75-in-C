#include <stdio.h>

int longestOnes(int* nums, int numsSize, int k) {
    int left = 0, right = 0;
    int maxOnes = 0;
    int zerosCount = 0;

    while (right < numsSize) {
        if (nums[right] == 0) {
            zerosCount++;
        }

        // If the number of zeros exceeds k, shrink the window
        while (zerosCount > k) {
            if (nums[left] == 0) {
                zerosCount--;
            }
            left++;
        }

        // Calculate the maximum length of the subarray
        maxOnes = (right - left + 1) > maxOnes ? (right - left + 1) : maxOnes;

        right++;
    }

    return maxOnes;
}

// int main() {
//     int nums1[] = {1,1,1,0,0,0,1,1,1,1,0};
//     int k1 = 2;
//     int size1 = sizeof(nums1) / sizeof(nums1[0]);
//     printf("Output: %d\n", longestOnes(nums1, size1, k1));  // Output: 6

//     int nums2[] = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
//     int k2 = 3;
//     int size2 = sizeof(nums2) / sizeof(nums2[0]);
//     printf("Output: %d\n", longestOnes(nums2, size2, k2));  // Output: 10

//     return 0;
// }
