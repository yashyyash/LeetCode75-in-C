#include <stdbool.h>

bool increasingTriplet(int* nums, int numsSize) {
    if (numsSize < 3) {
        return false; // A triplet can't exist if there are less than 3 numbers
    }

    int first = INT_MAX, second = INT_MAX;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] <= first) {
            first = nums[i]; // Update the smallest number found so far
        } else if (nums[i] <= second) {
            second = nums[i]; // Update the second smallest number found so far
        } else {
            // If we find a number greater than both 'first' and 'second', return true
            return true;
        }
    }

    // If we never find such a triplet, return false
    return false;
}
