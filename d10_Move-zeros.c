void moveZeroes(int* nums, int numsSize) {
    int lastNonZeroFoundAt = 0;

    // Move all the non-zero elements to the beginning of the array
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[lastNonZeroFoundAt++] = nums[i];
        }
    }

    // Fill remaining elements with zero
    for (int i = lastNonZeroFoundAt; i < numsSize; i++) {
        nums[i] = 0;
    }
}
