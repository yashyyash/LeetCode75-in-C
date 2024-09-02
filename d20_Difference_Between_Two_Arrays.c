#include <stdio.h>
#include <stdlib.h>

// Function to find distinct elements in nums1 not in nums2
int* findDistinct(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* result = (int*)malloc(nums1Size * sizeof(int));
    int resultIndex = 0;
    
    for (int i = 0; i < nums1Size; i++) {
        int found = 0;
        for (int j = 0; j < nums2Size; j++) {
            if (nums1[i] == nums2[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            int isUnique = 1;
            for (int k = 0; k < resultIndex; k++) {
                if (result[k] == nums1[i]) {
                    isUnique = 0;
                    break;
                }
            }
            if (isUnique) {
                result[resultIndex++] = nums1[i];
            }
        }
    }
    *returnSize = resultIndex;
    return result;
}

// Main function to return the difference of two arrays
int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int** returnColumnSizes) {
    int* resultSize = (int*)malloc(2 * sizeof(int));
    
    int* distinctInNums1 = findDistinct(nums1, nums1Size, nums2, nums2Size, &resultSize[0]);
    int* distinctInNums2 = findDistinct(nums2, nums2Size, nums1, nums1Size, &resultSize[1]);
    
    int** result = (int**)malloc(2 * sizeof(int*));
    result[0] = distinctInNums1;
    result[1] = distinctInNums2;
    
    *returnSize = 2;
    *returnColumnSizes = resultSize;
    
    return result;
}

// int main() {
//     int nums1[] = {1, 2, 3};
//     int nums2[] = {2, 4, 6};
    
//     int returnSize;
//     int* returnColumnSizes;
//     int** result = findDifference(nums1, 3, nums2, 3, &returnSize, &returnColumnSizes);
    
//     printf("[");
//     for (int i = 0; i < returnSize; i++) {
//         printf("[");
//         for (int j = 0; j < returnColumnSizes[i]; j++) {
//             printf("%d", result[i][j]);
//             if (j < returnColumnSizes[i] - 1) {
//                 printf(",");
//             }
//         }
//         printf("]");
//         if (i < returnSize - 1) {
//             printf(",");
//         }
//     }
//     printf("]\n");
    
//     // Free the allocated memory
//     free(result[0]);
//     free(result[1]);
//     free(result);
//     free(returnColumnSizes);

//     return 0;
// }
